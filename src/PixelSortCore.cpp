//  PixelSort v1.6 - Max van Leeuwen - Copyright (C) 2019
//  See www.maxvanleeuwen.com/pixelsort for the additional gizmo, updates, and more information!


#include "DDImage/Row.h"
#include "DDImage/Knobs.h"
#include "DDImage/NukeWrapper.h"


using namespace DD::Image;
using namespace std;


static const char* const CLASS = "PixelSortCore";
static const char* const HELP = "Sort pixels in an orderly fashion. Use the PixelSort gizmo!";


class PixelSortCore : public Iop {

	// channels to sort
	ChannelSet allchannels;

	// these are the knobs on the node
	float Threshold;


public:


	PixelSortCore(Node* node) : Iop(node) {
		// input count - one for image, one for sort matte
		inputs(2);

		// channelmask default value
		allchannels = Mask_All;

		// default knob values
		Threshold = 0;
	}


	void _validate(bool);
	void _request(int x, int y, int r, int t, ChannelMask channels, int count);
	void engine(int y, int x, int r, ChannelMask channels, Row & row);

	const char* Class() const { return d.name; }
	const char* node_help() const { return HELP; }


	const char* input_label(int input, char* buffer) const
	{
		// give names to input pipes
		switch (input) {
		default:
			return "";
		case 1:
			return "sort (a)";
		}
	}


	virtual void knobs(Knob_Callback);
	static const Iop::Description d;
};


void PixelSortCore::_validate(bool for_real) {
	// get the information (bbox, resolution and all that) from the input and give it to the output
	copy_info();
}


void PixelSortCore::_request(int x, int y, int r, int t, ChannelMask channels, int count) {
	// request all image input data
	input(0)->request(x, y, r, t, allchannels, count);
	input(1)->request(x, y, r, t, Chan_Alpha, count);
}


void PixelSortCore::engine(int y, int x, int r, ChannelMask channels, Row& row) {

	// get data row for sort by-matte
	row.get(input1(), y, x, r, Chan_Alpha);

	// make a vector that stores the sort-matte input for one row
	std::vector<float> StoredSort(r);
	// make a pointer to the alpha channel of the sort-matte
	const float* INPSORT = row[Chan_Alpha];

	// only write to StoredSort if the position is a positive or zero integer (this can be unknown when the bbox is smaller)
	for (int XM = x >= 0 ? x : 0; XM < r; XM++) {
		//store matte input in a vector for later use
		StoredSort.at(XM) = INPSORT[XM];
	}


	// get data row for image
	row.get(input0(), y, x, r, channels);

	// for each channel (named z)
	foreach(z, channels) {

		// set image input pointer
		const float* INP = row[z];
		// set image output pointer
		float* OUTP = row.writable(z);


		// if this channel is not used, pass on its values
		if (!allchannels.contains(z)) {
			// wite original values for each pixel in row
			for (int X = x >= 0 ? x : 0; X < r; X++) {
				OUTP[X] = INP[X];
			}

			// go to next channel
			continue;
		}


		// create a temp row in memory to be able to swap values - this is where the sorting happens (a vector is not as fast as an array, but it supports a variable resolution)
		std::vector<float> Sorted(r);

		// go through all pixels in the row (left to right)
		for (int X = x >= 0 ? x : 0; X < r; X++) {
			// store all pixels in row as values in the temp row
			Sorted.at(X) = INP[X];
		}


		// go though all pixels in the row again, and write one pixel per iteration - which means X2 is our current position to write to
		for (int X = x >= 0 ? x : 0; X < r; X++) {

			// Store the value of the current position (as it will be overwritten, but we will need it at a later time)
			float OriginalValue = Sorted[X];

			// create a high score (start at the value of the current position, or black)
			float FoundValue = OriginalValue;

			// create a high score pixel index (start at the current position)
			int FoundPixel = X;

			// sorting cut-off
			bool SkipRestOfRow = false;

			// for each pixel in row
			for (int X2 = X; X2 < r; X2++) {

				// skip the rest of the row if the matte value is under threshold
				if (StoredSort[X2] < Threshold) {
					SkipRestOfRow = true;
				}

				// if a value found on the row is higher than the current record
				if (Sorted[X2] < FoundValue && !SkipRestOfRow) {
					if (StoredSort[X2] >= Threshold) {
					
						// set the record to this new value
						FoundValue = Sorted[X2];
						// remember the index of that pixel
						FoundPixel = X2;
					
					}
				}
			}


			// store to temp row to not forget the original pixel
			Sorted.at(FoundPixel) = OriginalValue;

			// output the newest and brightest pixel on its proper position
			OUTP[X] = FoundValue;
		}
	}
}


void PixelSortCore::knobs(Knob_Callback f) {
	// setup knobs and tooltips
	Newline(f);
	Float_knob(f, &Threshold, "threshold");
	Tooltip(f, "Skip sorting by 'sort' input alpha channel at this value.");
	Newline(f);
	Divider(f);
	Text_knob(f, "PixelSort v1.6\nMax van Leeuwen\nmaxvanleeuwen.com/pixelsort");
	Divider(f);
}


static Iop* build(Node *node) {
	return new NukeWrapper(new PixelSortCore(node));
}
const Iop::Description PixelSortCore::d("PixelSortCore", "PixelSortCore", build);
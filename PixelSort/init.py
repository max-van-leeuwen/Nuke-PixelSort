# See maxvanleeuwen.com/pixelsort for examples, updates, and more information!

# This script will automatically load the right OS and Nuke version of the PixelSortCore plugin.
# If you have compiled your own version of it, simply adding it to a (new) folder with the right Nuke version name will work!


# never block Nuke starting
try:

	# get operating sys
	ops = ''

	import platform
	if platform.system() == "Windows": # Windows
		ops = 'Windows'
	elif platform.system() == "Darwin": # Mac OS
		ops = 'MacOS'
	else: # Linux
		ops = 'Linux'


	# get nuke version
	import nuke
	ver = nuke.NUKE_VERSION_STRING
	ver = ver.split('v')[-2]


	# get path to current directory
	cd = os.path.dirname(os.path.realpath(__file__)).replace("\\", "/")


	# path to current PixelSortCore library
	p = cd + '/PixelSortCore/' + ops + '/' + ver


	# check if PixelSortCore dir exists
	import os.path
	if os.path.isdir(p):
		# add it to plugin paths so the shared library will be loaded
		nuke.pluginAddPath(p)

except Exception as e:
	print('PixelSort failed to load. Error:\n' + str(e))
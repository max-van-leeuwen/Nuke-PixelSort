<p>This download contains compiled files for both Windows and Linux, and you can use the source code to compile it yourself for Mac or unsupported Nuke versions!</p>
<p> </p>
<p> </p>
<p> </p>
<p><img src="https://maxvanleeuwen.com/wp-content/uploads/PixelSort_Node.png" alt="nuke pixelsort gizmo" width="156" height="116" /></p>
<p><img src="https://maxvanleeuwen.com/wp-content/uploads/PixelSort_Properties.png" alt="nuke pixelsort" /></p>
<p> </p>
<p> </p>
<p> </p>
<p>The sort input can be painted on:</p>
<p> </p>
<p><img src="https://maxvanleeuwen.com/wp-content/uploads/PixelSortPainting.gif" alt="pixelsorting plugin nuke" /></p>
<p><img src="https://maxvanleeuwen.com/wp-content/uploads/Painting.gif" alt="nuke pixelsort pixel sorting plugin" /></p>
<p> </p>
<p> </p>
<p> </p>
<p>Some examples of what you can do with it:</p>
<p> </p>
<p><img src="https://maxvanleeuwen.com/wp-content/uploads/04.jpg" alt="pixel sorting" width="573" height="322" /></p>
<p><img src="https://maxvanleeuwen.com/wp-content/uploads/03.jpg" alt="nuke pixel sorting" width="572" height="322" /></p>
<p><img src="https://maxvanleeuwen.com/wp-content/uploads/PIXELSORT_02-1-1116x837.jpg" alt="nuke plugin pixel sort" width="574" height="430" /></p>
<p> </p>
<p> </p>
<p> </p>
<p> </p>
<p>See my website (<a href="https://maxvanleeuwen.com/pixelsort">maxvanleeuwen.com/pixelsort</a>) for more information and examples!</p>
<p>Currently, PixelSort is compiled for the following systems:<br />Windows: 11.0, 11.1, 11.2, 11.3<br />Linux: 8.0, 9.0, 10.0, 10.5, 11.0, 11.1, 11.2, 11.3.</p>
<p><br />Once compiled, place the resulting file in the PixelSort folder, in a subfolder with the name of the version you compiled it for (in the same fashion as the other ones that are already there). The menu.py will automatically find it!</p>
<p> </p>
<p> </p>
<p> </p>
<p> </p>
<p><strong>Installation</strong></p>
<p> </p>
<p>1. Place the PixelSort folder in your .nuke folder (or somewhere else on your computer)</p>
<p><br />2. Go to your .nuke folder, and create a file called ‘init.py’. If such a file already exists, open it. You can find the .nuke folder here:</p>
<p style="margin-left: 30px;">Linux: /home/username/.nuke<br /> Windows: C:\Users\username\.nuke</p>
<p><br />3. In the init.py file, add this line of text to the end and save it:</p>
<p>nuke.pluginAddPath('./PixelSort')</p>
<p> </p>
<p> </p>
<p> </p>
<p><strong>Installation using NukeShared</strong></p>
<p> </p>
<p>1. Place the PixelSort folder in the '_AutoInstaller' repository.</p>
<p> </p>
<p>NukeShared is a way of installing plugins by dragging/dropping them in folders, see <a href="https://maxvanleeuwen.com/nukeshared" target="_blank">my website</a> (maxvanleeuwen.com/nukeshared) for more information.</p>
<p> </p>
<p> </p>
<p> </p>
<p> </p>
<p> </p>
<p><strong>Updates:</strong></p>
<p> </p>
<p>v1.6</p>
<p style="margin-left: 30px;">Simplified a lot, to make it more logical and cleaner (removed some experimental stuff)<br />Speed improvements!<br />Released code, so you can compile it yourself<br />Fixed some BBox and filtering issues with the gizmo</p>
<p>v1.5</p>
<p style="margin-left: 30px;">Linux compatibility<br />Added Mask input</p>

# See maxvanleeuwen.com/pixelsort for examples, updates, and more information!


# make gizmo item in menu
import nuke
nuke.menu('Nodes').addCommand('Filter/PixelSort', "nuke.createNode('PixelSort.gizmo')", icon='PixelSort.png')
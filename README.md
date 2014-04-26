arduino-direct-matrix-8x8
=========================

A small device that produce 8x8 display with a single ATmega microcontroler and a led display.

Todo
----
* Add a IR led/sensor to communicate with neighbours ;
* Add a switch to select "today's-mood".

See also
--------
* https://wiki.raumzeitlabor.de/wiki/Hacklace/en
* https://sites.google.com/site/tinymatrix/
* https://docs.google.com/viewer?a=v&pid=sites&srcid=ZGVmYXVsdGRvbWFpbnx0aW55bWF0cml4fGd4OjRkMWNjZjFhMWM5ZmYyMmM (TinyMatrix.c)
* http://tinkerlog.com/howto/64pixels/

Nuts & Bolts
--------------
How to store in flash:

	const unsigned char FONT_CHARS[96][5] PROGMEM =
	{
		{ 0x00, 0x00, 0x00, 0x00, 0x00 },  // (space)
		{ 0x00, 0x00, 0x5F, 0x00, 0x00 },  // !
		{ 0x00, 0x07, 0x00, 0x07, 0x00 },  // "
	...

How to read in flash:

	byte = pgm_read_byte(&(charset[c][y]));


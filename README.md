To compile:
make clean mytunes

To run:
./mytunes

The program reads the insert_beatles_tracks_rev1.txt script on startup.
To disable this behaviour comment out the lines:

  //initialize app with input script
  Command cmd = Command(".read insert_beatles_tracks_rev1.txt");
  executeCommand(cmd);

in the run() method at the start of the UI.cpp file.

You can then choose to read in another file by typing:

.read Part2TestScript.txt

This second script will showcase that all program behaviour is the same as the original and that the refactor has not
changed any aspect of the workings of the app. All delete functions and show functions will be tested. Add functions
have already been tested with first script that is read upon app launch.

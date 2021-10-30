#include <stdlib.h>

#include "soloud.h"
#include "soloud_speech.h"
#include "soloud_thread.h"

int main(int argc, char *argv[])
{

	SoLoud::Soloud soloud;
    soloud.init();
    soloud.setGlobalVolume(3.);

	SoLoud::Speech speech;
	speech.setText("Hello world");

	soloud.play(speech);
	while (soloud.getActiveVoiceCount() > 0) {
		SoLoud::Thread::sleep(100);
	}

	soloud.deinit();

	return 0;
}
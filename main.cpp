#include "window.hpp"

Window* game = nullptr;

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int main(int argc, char* argv[]){

	bool is_fullscreen = false;

	game = new Window();

	game -> init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, is_fullscreen);

	while(game -> get_running()){
		game -> event();
		game -> update();
		game -> render();

	}

	game -> clean();

	return 0;
}

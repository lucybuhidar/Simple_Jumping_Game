#include "window.hpp"

Window::Window(){
}

Window::~Window(){

}

void Window::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
	int flags = 0;

	if (fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}	

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
		/* SDL_INIT Confirmation */
		std::cout << "SDL Subsystem Initialized..." << std::endl;

		/* Window Creation */
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		/* Window Creation Confirmation */
				
		if (window){
			std::cout << "Window Created..." << std::endl;
		}

		/* Renderer Creation */

		renderer = SDL_CreateRenderer(window, -1, 0);

		/* Render Validation */

		if (renderer){
			/*set color*/
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

			/*confirmation*/
			std::cout << "Renderer created..." << std::endl;
		}

		/* set running true */
		is_running = true;
	}
	else{
	
		/* set running false */
		is_running = false;

	}
}

void Window::event(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type){
		case (SDL_QUIT):
			is_running = false;
			break;
		default:
			break;
	}
}

void Window::update(){
	SDL_GetMouseState(&mouse_pos_x, &mouse_pos_y);	
}

void Window::render(){
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Window::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	
	/*Clean Confirmation */
	std::cout << "Game Cleaned..." << std::endl;
}




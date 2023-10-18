#ifndef WINDOW_H
#define WINODW_H
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Window {
	
public:
	Window();
	~Window();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void event();
	void update();
	void render();
	void clean();
	bool get_running(){
		return is_running;
	}
private:
	bool is_running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int mouse_pos_x, mouse_pos_y;

};

#endif /* WINDOW_H */

all:
	g++ main.cpp window.cpp -lSDL2 -o main

run:
	@./main

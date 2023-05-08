// CSSDL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include "a.h"
#include <SDL_image.h>

SDL_Window* win;
SDL_Renderer* renderer;
SDL_Surface* imageSurface;
SDL_Texture* imageTexture;

int main(int argc, char*argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        SDL_Log("Can not init everything,%s", SDL_GetError());
        return 1;
    }
	win = SDL_CreateWindow("TANK", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	if (win == NULL) {
        SDL_Log("Can not init window,%s", SDL_GetError());
        return 1;
    }

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_Log("Can not init renderer,%s", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);

	imageSurface = IMG_Load("ball.png");
	imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_RenderCopy(renderer, imageTexture, NULL, NULL);

    SDL_RenderPresent(renderer);

    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_KEYDOWN:
                SDL_Quit();

            case SDL_QUIT:
                return 0;
            }
        }
    }



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    //SDL_Log("Hello SDL!");
    //std::cout << "Hello World!\n";
    //a();
    //system("pause");
    return 0;
}

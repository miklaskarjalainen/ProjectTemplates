
#include <iostream>
#include <SDL2/SDL.h>

#undef main

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Could not init SDL, because: " <<  SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Window* window = SDL_CreateWindow("my window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    bool done = false;

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    done = true;
                    break;
                }
                default:
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 217, 217, 217, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_Quit();

    return 0;
}



#include <iostream>
#include <SDL3/SDL.h>

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Could not init SDL, because: " <<  SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Window* window = SDL_CreateWindow("my window", 1280, 720, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    bool done = false;

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: {
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


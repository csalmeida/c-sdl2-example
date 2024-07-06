#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Defines the initial size of the window:
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char *argv[]) 
{
  // Initializes SDL with selected subsystems:
  int sdl = SDL_Init(SDL_INIT_VIDEO);

  // Exits if SDL was not initialized correctly:
  bool sdl_is_init = sdl == 0;
  if (!sdl_is_init) {
    fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Setting up a window:
  // https://wiki.libsdl.org/SDL2/SDL_CreateWindow
  SDL_Window *window = SDL_CreateWindow(
    "🎉 SDL2 Window 🎉", 
    SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, 
    SCREEN_WIDTH, 
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN
  );

  if (window == NULL) {
    fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  // Create a 2D rendering context for a window.
  // https://wiki.libsdl.org/SDL2/SDL_CreateRenderer
  // https://wiki.libsdl.org/SDL2/SDL_RendererFlags
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  // Destroys window if renderer fails to instantiate:
  if (renderer == NULL) {
    SDL_DestroyWindow(window);
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  // https://wiki.libsdl.org/SDL2/SDL_Event
  SDL_Event event;
  int quit = 0;

  // Quits the program is the quit event is issued:
  while (!quit) {
    while(SDL_PollEvent(&event)) {
      switch (event.type)
      {
      case SDL_QUIT:
        quit = 1;
        break;
      
      default:
        break;
      }
    }

    // Draw a black frame to the screen:
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  printf("SDL2: Done! 🎉\n");
  return EXIT_SUCCESS;
}
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

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

  printf("🎉 Hello, SDL 🎉\n");
  return 0;
}
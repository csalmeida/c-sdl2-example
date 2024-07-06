# Set the compiler:
CC       := gcc

# Set compiler flags:
C_FLAGS := `sdl2-config --cflags` -ggdb3 -O0 --std=c99 -Wall

# The file name to be compiled.
# Changes executable name:
FILE_NAME := main

# bin is where executables are saved to.
# src is where source code is located.
BIN     := bin
SRC     := src

# Paths to include in building the program:
INCLUDE_PATHS := include
LIBRARY_PATHS = lib

# Specify the libraries being used:
LIBRARIES   := -lSDL2 -lSDL2_image  # Don't forget that -l is the option
EXECUTABLE  := $(FILE_NAME)
SOURCES := $(shell find $(SRC) -name "*.c") # Finds files to compile.

.PHONY: clean all

# Attempt to execute the program:
all: $(BIN)/$(EXECUTABLE)

# Cleans the bin directory and runs the executable.
run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/$(FILE_NAME).c
	$(CC) $(C_FLAGS) $^ -o $@ -I$(INCLUDE_PATHS) -L$(LIBRARY_PATHS) $(LIBRARIES)

# Removes main and main.* folders, keeps sdl2-config:
clean:
	- rm -f ./bin/$(EXECUTABLE)
	- rm -rf ./bin/$(EXECUTABLE).*

# The final command should look like: 
# gcc `sdl2-config --cflags` -ggdb3 -O0 --std=c99 -Wall src/main.c -o bin/main -Iinclude -Llib -lSDL2 -lSDL2_image  
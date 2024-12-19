# C SDL2 Example

A setup of SDL2 with all the libraries available in the project folder.

## Setup

To compile the program use:

```bash
make
```

To run it:

```bash
./bin/main
```

To clear compiled files:

```bash
make clean
```

> [!TIP]
> If VS Code is not detecting the path to SDL add them to the path by adding `"${workspaceFolder}/include"` in the Microsoft C/C++ Extension.

# Examples

## `main.c`
![main.c](./screenshots/main.png)

## `blank_window.c`
![blank_window.c](./screenshots/blank_window.png)


# Troubleshooting

## The Zed Editor does not find SDL2

The Zed editor might have difficulties finding SDL2 in the include folder. To fix this, you'll need to use absolute paths in your `.clangd` file. To get the absolute path:

1. Change directory to your project folder
2. Use `pwd` to get the absolute path
3. Create a `.clangd` file in your project root that looks similar to this:

```yaml
CompileFlags:
  Add:
    - "-I/Users/username/Projects/my-project"
    - "-I/Users/username/Projects/my-project/include"
    - "-I/Users/username/Projects/my-project/include/SDL2"
```

Replace `/Users/username/Projects/my-project` with the output from your `pwd` command.

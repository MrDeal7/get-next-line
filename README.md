# get_next_line

A C function that reads a file descriptor one line at a time.

## Description

`get_next_line` returns the next line from a file descriptor each time it is called. It handles files, standard input, or any valid file descriptor. The function uses a static buffer internally and supports a configurable buffer size via the `BUFFER_SIZE` macro.

## Prototype

```c
char *get_next_line(int fd);
```

- **fd** — the file descriptor to read from
- **Returns** — the next line (including the trailing `\n` if present), or `NULL` on end of file or error

## Files

| File | Description |
|---|---|
| `get_next_line.c` | Main function |
| `get_next_line_utils.c` | Helper functions |
| `get_next_line.h` | Header file |
| `get_next_line_bonus.c` | Bonus — supports multiple file descriptors |
| `get_next_line_utils_bonus.c` | Bonus helper functions |
| `get_next_line_bonus.h` | Bonus header file |

## Usage

Include the header and compile the source files together with your project:

```bash
cc -Wall -Wextra -Werror -DBUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Example:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd;
    char  *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Buffer Size

The buffer size defaults to `10` and can be overridden at compile time:

```bash
cc -DBUFFER_SIZE=512 ...
```

## Author

divalent — 42 school project

#include "main.h"
#include <stddef.h>

/**
 * read_textfile - it reads a text file and prints it to the POSIX stdio
 * @filename: name of the file
 * @letters: it is the number of letters it should read and print
 *
 * Return: it returns the actual number of letters and prints it
 * if it cannot be opened, it should return 0
 * if the filename is NULL, return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = 0;
	int reads = 0;
	int output = 0;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	reads = read(fd, buffer, letters);
	if (reads == -1)
	{
		free(buffer);
		return (0);
	}

	output = write(STDOUT_FILENO, buffer, reads);
	if (output == -1 || output != reads)
	{
		free(buffer);
		return (0);
	}
	close(fd);
	free(buffer);
	return (output);
}

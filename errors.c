#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 * _putfdesc - writes the character c to given fdesc
 * @c: The character to print
 * @fdesc: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfdesc(char c, int fdesc)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fdesc, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 *_putsfdesc - prints an input string
 * @str: the string to be printed
 * @fdesc: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfdesc(char *str, int fdesc)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x += _putfdesc(*str++, fdesc);
	}
	return (x);
}


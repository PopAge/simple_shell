#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int x, z, t, p, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, z = 0; z < numwords; z++)
	{
		while (is_delim(str[x], d))
			x++;
		t = 0;
		while (!is_delim(str[x + t], d) && str[x + t])
			t++;
		s[z] = malloc((t + 1) * sizeof(char));
		if (!s[z])
		{
			for (t = 0; t < z; t++)
				free(s[t]);
			free(s);
			return (NULL);
		}
		for (p = 0; p < t; p++)
			s[z][p] = str[x++];
		s[z][p] = 0;
	}
	s[z] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int x, z, t, p, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, z = 0; z < numwords; z++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		t = 0;
		while (str[x + t] != d && str[x + t] && str[x + t] != d)
			t++;
		s[z] = malloc((t + 1) * sizeof(char));
		if (!s[z])
		{
			for (t = 0; t < z; t++)
				free(s[t]);
			free(s);
			return (NULL);
		}
		for (p = 0; p < t; p++)
			s[z][p] = str[x++];
		s[z][p] = 0;
	}
	s[z] = NULL;
	return (s);
}


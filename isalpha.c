#include "shell.h"

/**
 * interactive - returns true
 * @info: struct address
 * Return: 1 in success , 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter character
 * @c: the char to be check
 * @delim: the delimeter string
 * Return: 1 if true, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabet
 * @c: The character for input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts string to integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number
 */

int _atoi(char *s)
{
	int count, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (count = 0; s[count] != '\0' && flag != 2; count++)
	{
		if (s[count] == '-')
			sign *= -1;

		if (s[count] >= '0' && s[count] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[count] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

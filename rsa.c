#include "main.h"

/**
 * main - a function that will factorise a number with the prime factor
 * it read the numbers from a file
 * @argc: argument count
 * @argv: the file to be passed
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	ssize_t bufferSize = 0;
	char *buffer = NULL;
	size_t n;
	char *token;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: .factors <file>\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "cant open file\n");
		exit(EXIT_FAILURE);
	}

	while ((bufferSize = getline(&buffer, &n, fd)) != -1)
	{
		token = strtok(buffer, " \n");
		factorize(token);
	}

	return (0);
}

/**
 * factorize : a function that find the factor of buf
 * @buf: the number is passed as a string
 */
void factorize(char *buf)
{
	long long num = atoll(buf);
	long long x = 612852475143;
	long long n = 2;
	long long check = num / 2;
	long long prime;
	
	if ((num % n) == 0)
	{
		printf("%lld=%lld*%lld\n", num, check, n);
	}
	else
	{
		for(n = 3; n < check; n = n + 2)
		{
			if ((num %  n) == 0)
			{
				check = num / n;
				if ((num % n) == 0)
				{
					printf("%lld=%lld*%lld\n", num, check, n);
					break;
				}
			}
			check = num / n;
		}
		
	}
}

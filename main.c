#include "shell.h"
#include <unistd.h>

/**
 * main - write a unix command interpreter
 *@argc: argc int
 *@argv: pointer string to argv
 *@env: pointer string to env
 *Return: 0
 */

int main(int argc, char *argv[], char **env)
{

	char *prompt = "$ ";
	char *command = NULL;
	size_t num = 0;
	ssize_t num_of_char;

	(void)argc;
	(void)argv;
	(void)env;

	while (1)
	{
		printf("%s", prompt);
		num_of_char = getline(&command, &num, stdin);
		printf("%s", command);
		if (num_of_char == -1)
		{
			perror("Error (getline)");
			free(command);
			/*exit(EXIT_FAILURE);*/

		}

		if (command[num - 1] == '\n')
			command[num - 1] = '\0';
	}
	return (0);
}

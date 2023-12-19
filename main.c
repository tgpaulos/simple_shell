#include "main.h" 



void display_prompt(const char* prompt) {
	write(STDOUT_FILENO, prompt, strlen(prompt));
}

void read_input(char** line, size_t* len) {
	getline(line, len, stdin);
}

void tokenize_input(char* input, char** argv) {
	
	unsigned int i = 0;
	
	argv[i] = strtok(input, " \n");
	while (argv[i]) {
		i++;
		argv[i] = strtok(NULL, " \n");
	}
}

void execute_command(char** argv)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1) {
		perror("Error:");
		exit(1);
	}
	if (child_pid == 0) {
		if (execve(argv[0], argv, NULL) == -1) {
			perror("Error:");
		}
	} else {
		
		wait(&status);
	}
}

int main(void)
{
	
	char *buffer = "$ ";
	ssize_t input = 0;  
	char *line = NULL;
	size_t len = 0;
	char *argv[100];
	
	
	while (1)
	{
		display_prompt(buffer);
		read_input(&line, &len);

		if (input == (ssize_t)SIZE_MAX)
		{
			write(1, "\n", 1);
			free(line);
			break;
		}

		tokenize_input(line, argv);
		execute_command(argv);
	}

	return 0;
}

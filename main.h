#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt(const char* prompt);
void read_input(char** line, size_t* len);
void tokenize_input(char* input, char** argv);
void execute_command(char** argv);

#endif

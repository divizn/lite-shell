#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

const char *COMMANDS[1] = {"exit"};

// TODO: read path to see what commands can be executed

void execute_command(char *command);


int main() {
  char input[100];

  while (1) {
    printf("$ ");

    fflush(stdout);
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';
    
    for (int i=0; i < sizeof(COMMANDS)/sizeof(COMMANDS[0]); i++) {
      if (input == "") {
        break;
      }
      if (strcmp(input, COMMANDS[i]) == 0) {
        execute_command(input);
      }
      else {
        printf("scsh: command not found: %s\n", input);
      }
    }
  }

  return 0;
}

void execute_command(char *command) {
  if (strcmp(command, "exit") == 0) {
    exit(0);
  }
}

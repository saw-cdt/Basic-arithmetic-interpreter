#include <stdio.h>
#include <stdbool.h>

#define INPUT_LENGTH 2048

static char input[INPUT_LENGTH];

void interpret(char *str) {
	size_t i = 0;
	while(str[i] != '\0') {
		printf("%c\n",str[i]);
		i++;
	}
}

int main(){
	printf("I'm listening...\n");
	printf("Press Ctrl + c to get out\n\n");

	while(true) {
		printf(">>> ");
		fgets(input,INPUT_LENGTH,stdin);
		interpret(input);
	}
}

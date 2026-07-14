#include <stdio.h>
#include <stdbool.h>

#define INPUT_LENGTH 1000

void interpret(char *str) {
	size_t i = 0;
	while(str[i] != '\0') {
		printf("%c\n",str[i]);
		i++;
	}
}

int main(){
	char output[INPUT_LENGTH];
	printf("I'm listening...\n");

	while(true) {
		printf(">>> ");
		fgets(output,INPUT_LENGTH,stdin);
		interpret(output);
	}
}

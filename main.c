#include <stdio.h>
#include <stdbool.h>

#define INPUT_LENGTH 2048

// Type definitions
#define INT 0
#define OPERATOR 1

// Token struct def
typedef struct {
	int type;
	int number_value;
	char operator_value;
} Token;

// Buffer input size
static char input[INPUT_LENGTH];

// Token initialization
Token current_token;
int current_position = 0;

bool is_digit(char c) {
	return c >= '0' && c <= '9';
}

void getNextToken(char *text){
	// Get text current char to tokenize
	char c = text[current_position];

	// Check for token type
	if ( is_digit(c) ) {
		current_token.type = INT;
		current_token.number_value = c - '0';
	} else {
		current_token.type = OPERATOR;
		current_token.operator_value = c;
	}
}

void lexer(char *input) {
	getNextToken(input);
}

int main(){
	printf("I'm listening...\n");
	printf("Press Ctrl + c to get out\n\n");

	while(true) {
		printf(">>> ");
		fgets(input,INPUT_LENGTH,stdin);
		lexer(input);
	}
}

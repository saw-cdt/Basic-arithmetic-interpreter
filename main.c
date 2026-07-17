#include <stdio.h>
#include <stdlib.h>
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
		current_token.operator_value = ' ';
	} else {
		current_token.type = OPERATOR;
		current_token.operator_value = c;
		current_token.number_value = 0;
	}
	current_position++;
}

void parser(int type) {
	if(current_token.type != type) {
		printf("Syntax Error: Token type not expected in position %d\n", current_position);
		exit(-1);
	}
}

void lexer(char *input) {
	getNextToken(input);
	parser(INT);
	int right = current_token.number_value;

	getNextToken(input);
	parser(OPERATOR);
	int op = current_token.operator_value;
	
	getNextToken(input);
	parser(INT);
	int left = current_token.number_value;

	current_position = 0;
	
	if (op == '+') {
		printf("%d\n", right + left);
	} else if (op == '-') {
		printf("%d\n", right - left);
	}
};

void clear_screen() {
	printf("\x1B[2J\x1B[H");
}

int main(){
	clear_screen();
	printf("I'm listening...\n");
	printf("Press Ctrl + c to get out\n\n");

	while(true) {
		printf(">>> ");
		fgets(input,INPUT_LENGTH,stdin);
		lexer(input);
	}
}

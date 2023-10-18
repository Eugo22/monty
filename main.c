#include "main.h
int stack[STACK_SIZE];
int top = -1;
/**
 *
 */
void push(int value, int line_number)
{
	if (top >= STACK_SIZE - 1)
	{
		fprintf(stderr, "Error: Stack overflow at line %d\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top++;
		stack[top] = value;
	}
}

/**
 *
 */
void pall()
{
	int i;
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
/**
 * main - checks code.
 *
 * Return: Always return 0.
 */
int main(void)
{
	char opcode[4];
	int arg;

	while (scanf("%s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (scanf("%d", &arg) != 1)
			{
				fprintf(stderr, "Error: Invalid argument for push at line %d\n", arg);
				exit(EXIT_FAILURE);
			}
			push(arg, arg);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall();
		}
		else
		{
			fprintf(stderr, "Error: Unknown opcode %s at line %d\n", opcode, arg);
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}

/*
Tom Busby
https://github.com/Nimdoc/BadCode.rocks-Diamond

To the extent possible under law, Tom Busby has waived all copyright and related or neighboring rights to BadCode.rocks-Diamond. This work is published from: United States. 
*/

#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[])
{

	if(argc != 2)
	{
		printf("USAGE: diamond.out [UPPERCASE LETTER]\n");
		exit(0);
	}
	else if((argv[1][0] < 'A') || (argv[1][0] > 'Z'))
	{
		printf("USAGE: diamond.out [UPPERCASE LETTER]\n");
		exit(0);
	}


	char letter = argv[1][0];
	int size = (((int)letter - ((int)'A')) * 2) + 1;	

	// Dynamically allocate an array for the field according to the letter chosen	
	char *field = (char *)malloc((size * size) * sizeof(char));

	// Fill the field with periods to start out
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			*(field + (i*size) + j) = ' ';

	int vel_x = 1;
	int vel_y = -1;

	// Starting position
	char *pos = (field + (((int)letter - ((int)'A')) * size) + 0);

	char cur = letter;

	int let_delta = -1;

	while(*pos == ' ')
	{
		*pos = cur;
		cur += let_delta;

		pos = pos + (size * vel_y) + vel_x;

		// Getting to the letter A means you're bouncing off the top or bottom
		if(cur == 'A')
		{
			vel_y = -vel_y;
			let_delta = -let_delta;
		}
		// Getting to the letter E means you're bouncing off the sides
		if(cur == letter)
		{
			vel_x = -vel_x;
			let_delta = -let_delta;
		}
	}

	for(int i = 0; i < size; i++)
	{
                for(int j = 0; j < size; j++)
                        printf("%c", *(field + (i*size) + j));

		printf("\n");
	}

	free(field);
}

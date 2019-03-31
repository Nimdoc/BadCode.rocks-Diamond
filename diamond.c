#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[])
{

	if(argc != 2)
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

	int vel_x = -1;
	int vel_y = 1;

	int pos_x = (int)letter - ((int)'A');
	int pos_y = 0;

	int let_delta = -1;

	int done = 0;

	while(!done)
	{
		*(field + (pos_x * size) + pos_y) = letter;
		letter += let_delta;

		pos_x += vel_x;
		pos_y += vel_y;

		if((pos_x == 0) || (pos_x == (size - 1)))
		{
			vel_x = -vel_x;
			let_delta = -let_delta;
		}
		if((pos_y == 0) || (pos_y == (size - 1)))
		{
			vel_y = -vel_y;
			let_delta = -let_delta;
		}

		if(*(field + (pos_x * size) + pos_y) != ' ')
			done = 1;
	}

	for(int i = 0; i < size; i++)
	{
                for(int j = 0; j < size; j++)
                        printf("%c", *(field + (i*size) + j));

		printf("\n");
	}

	free(field);
}

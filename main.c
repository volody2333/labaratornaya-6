#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	FILE *input, *output;
	char line[100];
	char fam[50], im[50], otch[50];
	int god;
	int count = 0;
	
	input = fopen("input.txt", "r");
	
	if (input == NULL)
	{
		printf("Error! File input.txt not found!\n");
		printf("Creat file input.txt in the program folder\n");
		system("pause");
		return 1;
	}
	output = fopen("output.txt", "w");
	if (output == NULL)
	{
		printf("Error! I can't create a file output.txt\n");
		fclose(input);
		system("pause");
		return 1;
	}
	printf("Read file input.txt...\n\n");
	
	while (fgets(line, 100, input) != NULL)
	{
		count++;
		if (line[strlen(line)-1] == '\n')
		{
			line[strlen(line)-1] = '\0';
		}
		printf("Line %d: %s\n", count, line);
		sscanf(line, "%s %s %s %d", fam, im, otch, &god);
		
		if (god > 1980)
		{
			fprintf(output, "%s %s %s %d\n", fam, im, otch, god);
			printf(" --> Wrote in output.txt: %s %s %s %d\n", fam, im, otch, god);
			
		}
		else
		{
			printf(" --> Missed (god %d <= 1980)\n", god);
		}
		printf("\n");
	}
	fclose(input);
	fclose(output);
	
	printf("======================\n");
	printf("Ready! Total read: %d line\n", count);
	printf("Result write in file output.txt\n");
	printf("======================\n");
	
	system("pause");
	return 0;
}

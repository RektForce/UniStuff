#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.c"

char *Input_File ="";
char *Output_File="";
int Ignore_Case=0;
int Word_Count =0;

int main(int argc, char **argv) {

	//A loop to check the actual arguments and to see if they are legal or not 
	if( argc > 4 < 7 && strstr(argv[1], "-i") && strstr(argv[3],"-o") )
	{
		//Extracts the input and output file names to use later
		Input_File =argv[2];
		Output_File =argv[4];
		
		//Another condition to check to see if case is ignored or not
		if(argc > 5 && strstr(argv[5], "-c"))
		{
			printf("Case will be ignored.\n");
			Ignore_Case = 1;
		}
		else{printf("Case will not be ignored!\n");}
	}
	else
	{
		//executes if the arguments are not as expected 
		printf("The command line arguments are not valid, the program will now terminate. \n");
		exit(0);
	}
	File_Processor();
}

int File_Processor()
{
	FILE* File_Editor;
	File_Editor = fopen(Input_File, "r");
	
	if(File_Editor==NULL)
	{
		printf("The file is not found, The program will now terminate");
	}
	while(!feof(File_Editor))
	{
		char Temp_Word[50];
		fscanf(File_Editor, "%s", Temp_Word);
		Word_Count++;
	}
	fclose(File_Editor);
	Create_Array(Word_Count);
	File_Editor = fopen(Input_File, "r");
	while(!feof(File_Editor))
	{
		
		char Raw_Word[50];
		fscanf(File_Editor, "%s", Raw_Word);
		
		//Removing Punctuation
		char Edited_Word[50]="";
		int Edit_Count=0;
		for(int i=0; i<Raw_Word[i]; i++)
			{
				//A simple if statement to check if the current character is a punctuation
				if(isalpha(Raw_Word[i]))
				{
					//printf("%c\n",Processing_Word[i]);
					if(Ignore_Case==1)
					{
						Raw_Word[i] = tolower(Raw_Word[i]);
					}
				
					Edited_Word[Edit_Count] = Raw_Word[i];
					Edit_Count++;
				}
			}
	
		Add_To_Array(Edited_Word);
		//printf("%s\n", Edited_Word);
	}
	//printf("%d", Word_Count);
	Print_All(Output_File);
	fclose(File_Editor);
	return 0;
}
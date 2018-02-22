#include<stdio.h>
#include<conio.h>
#pragma warning(disable:4996)

int Array_Size=0;;
int Array_Index=0;
int Unique_Words=0;
FILE *Writer;
struct WordElement
{
	int Count;
	char Word[50];
	int Printed;
};

struct WordElement *StructPointer; //just a pointer to a structure

int Create_Array(int Size){
StructPointer = malloc((Size*50) * sizeof(StructPointer));
if(NULL == StructPointer)
{
   perror("malloc failure");
   exit(EXIT_FAILURE);
}
Array_Size = Size;
return 0;
}
int run_Count=0;
int Add_To_Array(char Word[50]){
	int Word_Found=0;
	for(int i=0; i < Unique_Words && Word_Found!=1; i++)
	{
		if(strcmp(StructPointer[i].Word, Word)==0) // This should only run if the word exists in struct array 
		{
			StructPointer[i].Count++;
			//printf("incrementing the count\n");
			Word_Found=1;

		}
	
	}

	if(Word_Found==0) // if the above if statement doesn't evaluate, this should run 
	{
		//printf("it crashes here.. %d\n",Array_Index);
		strcpy(StructPointer[Array_Index].Word, Word); //copying the word passed by the main function to the struct array at a specific 
		StructPointer[Array_Index].Printed=0;
		//StructPointer[Array_Index].Word = strdup(Word);
		StructPointer[Array_Index].Count=1;
		//printf("WORD: %s\n", StructPointer[Array_Index].Word); // printing it just to make sure it got copied correctly
		Array_Index++;
		Unique_Words++;
	}
	
	return 0;
}

int Print_All(char File_Name[50])
{
	Writer = fopen(File_Name, "w");
	 if(Writer == NULL){
     fprintf(stderr,"Error Opening File");
     exit(EXIT_FAILURE);
	}
	fprintf(Writer, "Total Number of Words: %d , \t Total Number of Unique Words: %d\nWord    :    Count\n\n", Array_Size, Unique_Words);
	
	 for(int i=0; i < Unique_Words ; i++)
	{
		//fprintf(Writer, "%s\t\t%i\n",StructPointer[i].Word, StructPointer[i].Count);
		char Sort_Word[50];
		int Sort_Count=0;
			for(int j=0; j < Unique_Words; j++)
			{
				if(StructPointer[j].Count > Sort_Count  && StructPointer[j].Printed ==0)
				{
					strcpy(Sort_Word, StructPointer[j].Word);
					Sort_Count = StructPointer[j].Count;
					StructPointer[j].Printed=1;
				}
			}
			fprintf(Writer, "%s    :    %d\n",Sort_Word, Sort_Count);
		//SORTING
		
		
	} 
	free(StructPointer);
	fclose(Writer);
	printf("Output File Saved!\n");
	return 0;
}

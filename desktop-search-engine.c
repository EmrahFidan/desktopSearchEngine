#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// recursive search algorithm function
int search (char*searching,char A[1000][20],int b);

// global variable
 int i=0;
 int main(){
 	
 	FILE* fil;
	FILE*ign;
	FILE*word;
	
	int j,k=0,m,a,result;
	
	char A[1000][20];
	char B[1000][20];
	char fname[10];
	char trump[20];
	char searching[20];
	char line[100]; 
	char delim[] =" . ,\n   ";
	char delim2[]=".   ,";
	char *separator;
	char *ignseparator;
	
	// Getting a file name from the user
	printf("please enter your file name: ");
	scanf("%s",&fname);
	printf("\n");
	// strcat == insert function in string
	strcat(fname,".txt");
	fil=fopen(fname,"r");
	
	// Sending the elements of the file to the array indexes
	if (NULL == fil) {
		printf("file can't be opened \n");
	}
	while (fgets(line, sizeof(line), fil)) {
		separator = strtok(line, delim);
			while(separator != NULL)
			{
				strcpy(A[i++],separator);
				separator = strtok(NULL, delim);	
  				
			}		
		}
		fclose(fil);
		// A new frequency list showing how many times the array's elements repeat
		int freqlist[i];
			for(j=0;j<=i;j++)
			{
				freqlist[j]=0;
			}
			// Assign the elements of the file formed in prohibited words as a array index
	ign=fopen("ignoreList.txt","r");
		
			if (NULL == ign) {
		printf("file can't be opened \n");
	}
	
	while (fgets(line, sizeof(line), ign)) {
		ignseparator = strtok(line, delim);
			while(ignseparator != NULL)
			{
				strcpy(B[k++],ignseparator);
		     	ignseparator = strtok(NULL, delim);	
  				
			}		
		}
		fclose(ign);
		// I used the strcmp photo to compare the two arrays
			for(j=0;j<=i;j++)
		{
			for(m=0;m<=k;m++)
			{
				if(strcmp(A[j],B[m])==0)
				{
					// I assigned indices with overlapping words as spaces
					  strcpy(A[j],"");
				}
			}
		}
		// I wrote the elements of my knee in alphabetical order
			for(j=0;j<=i;j++)
			{
			for(m=0;m<=k;m++)
			{
				if(strcmp(A[j],A[m])<0)
				{
					  strcpy(trump,A[j]);
					  strcpy(A[j],A[m]);
					  strcpy(A[m],trump);
				}
	      }
	      }
		// I find the frequency numbers of the elements of my knee
		for(j=0;j<=i;j++)
		{
			for(m=0;m<=i;m++)
			{
				if(strcmp(A[j],A[m])==0 && strcmp(A[j],"")!=0)
				{
					freqlist[j]=freqlist[j]+1;
				}
			}
		}
		// I throw repetitive values as spaces so that my knee does not have more than one word
	for(j=0;j<=i;j++)
		{
			for(m=0;m<=i;m++)
			{
				if(strcmp(A[j],A[m])==0 && j!=m)
				{
					  strcpy(A[m],"");
				}
			}
		}
	// I deleted all the spaces and printed my created knee to a new word file
	word=fopen("word.txt","w");
		
	     for(j=0;j<=i;j++)
		{
			if(strcmp(A[j],"")!=0)
			{
			printf("%s,%d\n", A[j],freqlist[j]);
			fprintf(word,"%s\n",A[j]);
			}
		}
		fclose(word);
		printf("\n\n");
		
	// the user enters the word he is looking for
	while(strcmp(searching,"0")!=0 && NULL!=fil)
	{
		printf("(0 for exist) Enter a search string:");
		scanf("%s",searching);
		// The presence of the word searched by the operations made over the recursive function is questioned
		int h=0;
			 result = search(searching,A,h);
			 
		  	if(result!=-1)
		  	{
		  		printf("The word- %s - exist in the file\n",A[result-1]);
			}
			if (result==-1 )
			{
				printf("The word is not in the file\n");
			}
	}
	printf("--ENDD--");
			
	 
		  
			return 201805070;
		}


		int search (char*searching,char A[1000][20],int b)
	{
		// base cases
		if(strcmp(A[b++],searching)==0)
		{
			return b;
		}
		else if (b==i)
		{
			return -1;
	 }
	 // recursive case
		else
		{
	   	return search(searching,A,b);
		}
	}
	




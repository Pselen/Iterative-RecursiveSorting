//Selen Parlar / 150113049 / CSE Assingnment #5
//Import some C libraries and define the constant variables..

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define WORDLENGTH 300

//Declare and initialize the variables.
void iterativeSorting();
void recursiveSorting(int);
int k,s,i,j;
char word[WORDLENGTH][1000],a[1000];
char readingFile[25], outputFile[25], outputFile2[25];
FILE *fPointer;
FILE *output;
double total_time_spent2;

//Main method which includes reading file and calling methods.
int main()
{
    //Takes the file name from user.
    printf("Enter the path of file: \n");
    scanf("%s",readingFile);
    fPointer = fopen(readingFile,"r");

    if ((fPointer=fopen(readingFile,"r"))==0)
    {
        puts("Error while opening the file.");
        exit(1);
    }
    //Scans each word in file.
    for (k=0;k<WORDLENGTH;k++)
		fscanf(fPointer,"%s",word[k]);

    //Close the file.
 	fclose(fPointer);

    int sortingType;
    //Ask user to whether use iterative version or recursive version.
    printf("Press 1 for iterative sorting and press 2 for recursive sorting:\n");
    scanf("%d", &sortingType);
    //If he/she enters 1, programme will sort the words as iteratively.
    if (sortingType==1){
        printf("->You chose iterative sorting\n");
        //Calls the iterative sorting function.
        iterativeSorting();
    }
        //if he/she enters 2, the programme will sort the words as recursively.
        else if (sortingType==2){
        printf("->You chose recursive sorting\n");
        //Declare variables.
        int y;
        int t2;
        double total_time_spent2=0;
        clock_t begin2,end2;
        double time_spent2;
        //The loop to determine execution time for 5 times.
        for(t2=0; t2<5; t2++){
        //Starts the clock.
        begin2= clock();
            //The loop for printing words and calls the recursion function.
            for(y = 0; y < WORDLENGTH;y++ ){
                recursiveSorting(0);
            }
            //Stops the clock.
            end2=clock();
            //Calculates the time for execution.
            time_spent2 = (double)(end2-begin2)/CLOCKS_PER_SEC;
            //Finds out the total execution time.
            total_time_spent2+=time_spent2;
        }
            //Prints out the total time for recursion.
            printf("\nAverage time spent for execution of recursive sorting: %lf\n", total_time_spent2/5.0);
        //Creates a new file wherever user wants and put the sorted in the file.
        FILE *output;
        printf("\nEnter a path in which output file will be created:\n ");
        scanf("%s", outputFile2);
        output = fopen(outputFile2,"w");
            int i;
            for(i=0;i<WORDLENGTH;i++){
            fprintf(output,"%s\n",word[i]);
            }
            printf("Output file has created.");
            //Close the output file.
            fclose(output);

        //return 0;
        return EXIT_SUCCESS;
        //End of main method.
        }
}

//Function for iterative sorting.
void iterativeSorting()
{
int t;
double total_time_spent=0;
clock_t begin,end;
double time_spent;

//In order to determine execution time of the iterative sorting function for 5 times, we need a for loop.
for(t=0; t<5; t++){
//Starting point of clock.
begin=clock();
//This method compares 2 words if one's first letter is greater than the other one, it saps the words.
for(i=0;i<WORDLENGTH;i++)
		for(j=0;j<WORDLENGTH-1;j++)
			if(strcasecmp(word[j+1],word[j])<0 )
			{
				strcpy(a,word[j]);
				strcpy(word[j],word[j+1]);
				strcpy(word[j+1],a);
			}
//Finishing point of clock.
end =clock();
//Calculate the time spent between 2 clock parametersç
time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//Finds out the total execution time.
total_time_spent+=time_spent;
}
//Prints the execution time.
printf("\nAverage time spent for execution of iterative function: %lf ", total_time_spent/5.0);

    //Create a new file in which place user wants.
    FILE *output;
    printf("\nEnter the path of file for output:\n");
    scanf("%s", outputFile);
    output = fopen(outputFile,"w");

    //Writes every words to new file line by line and sorted.
    for(i=0;i<WORDLENGTH;i++)
		fprintf(fPointer,"%s\n",word[i]);
    //Close the output file.
	fclose(output);
}
//Function for recursive sorting.
void recursiveSorting(int j){
    //Compares two words recursively.
    if(j!=WORDLENGTH-1 && strcasecmp(word[j+1],word[j])<0){
            strcpy(a,word[j]);
            strcpy(word[j],word[j+1]);
            strcpy(word[j+1],a);
            return recursiveSorting(j+1);
    }
        else if(j<WORDLENGTH-1 && strcasecmp(word[j+1],word[j])==0){
            return recursiveSorting(j+1);
        }
            else if(j<WORDLENGTH-1 && strcasecmp(word[j+1],word[j])>0){
                return   recursiveSorting(j+1);
            }
}

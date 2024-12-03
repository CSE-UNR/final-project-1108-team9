// Waleed Naqshband, 
// 12/10/24
// Purpose: Madlibs Using 2D Arrays for Group Final

#include <stdio.h>
#define SIZE 100

void getWords(char inputArray[][SIZE], char madlibCharArray[][SIZE]);
void findInputWords(FILE* filePointer, int row, char array[row]);
void PrintText(FILE* madlib, int row, char *strings[row]);


int main(){
	
}

void getWords(char inputArray[][SIZE], char madlibCharArray[][SIZE]){
	int ind = 0;
	while(madlibCharArray[ind][0] != '\0'){
		if(madlibCharArray[ind][0] == 'N'){
			printf("Input a Noun: ");
		} else if(madlibCharArray[ind][0] == 'V') {
			printf("Input a Verb: ");
		} else {
			printf("Input an Adverb: ");
		}
		scanf("%s", &inputArray[ind][0]);
		ind++;
	}
}


void findInputWords(FILE* filePointer, int row, char array[row]) {
   char ch1, ch2;
   int index = 0;
   while (fscanf(filePointer, "%c", &ch1) == 1) {
       if (fscanf(filePointer, "%c", &ch2) == 1) {
           if ((ch2 == '\n' && (ch1 == 'N' || ch1 == 'V' || ch1 == 'A')) || (ch1 == '\n' && (ch2 == 'N' || ch2 == 'V' || ch2 == 'A'))) {
               if (ch2 == '\n') {
                   array[index] = ch1;
               }
               else {
                   array[index] = ch2;
               }
               index++;
           }
       }
   }
}



void PrintText(FILE* madlib, int row, char *strings[row]){
   char madin[MAXCHAR];
   int i;


   while(fscanf(madlib, "%s", madin) == 1){


       if(madin == "N\n\0" || madin == "A\n\0" || madin == "V\n\0"){
           printf("%s\n", strings[i]);
           i++;
       }


       else{
           printf("%s", madin);
       }
   }
}










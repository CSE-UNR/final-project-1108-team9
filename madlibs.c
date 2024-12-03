// Waleed Naqshband, Nicole Eames, Sarah Enlow
// 12/10/24
// Purpose: Madlibs Using 2D Arrays for Group Final

#include <stdio.h>

#define SIZE 100
#define FILE_NAME "madlib1.txt"

void getWords(char inputArray[][SIZE], char madlibCharArray[]);
void findInputWords(FILE* filePointer, int row, char array[row]);
void PrintText(FILE* madlib, int row, char *strings[row]);

int main(){
   FILE* filePointer;
   char stringArray[SIZE][SIZE];
   char charArray[SIZE];

   for (int i = 0; i < SIZE; i++) {
       charArray[i] = '\0';
       for (int j = 0; j < SIZE; j++) {
           stringArray[i][j] = '\0';
       }
   }

   filePointer = fopen(FILE_NAME, "r");
   if (filePointer == NULL) {
       printf("Error opening file.\n");
       return 0;
   }
   findInputWords(filePointer, SIZE, charArray);
   fclose(filePointer);

   getWords(charArray, stringArray);

   filePointer = fopen(FILE_NAME, "r");
   if (filePointer == NULL) {
       printf("Error opening file.\n");
       return 0;
   }
   PrintText(filePointer, SIZE, stringArray);
   fclose(filePointer);

   return 0;
}


//inputArray is string array. madlibCharArray is A N V
void getWords(char inputArray[][SIZE], char madlibCharArray[]){
   int ind = 0;
   while(madlibCharArray[ind] != '\0'){
       if(madlibCharArray[ind] == 'N'){
           printf("Please enter a noun: ");
       } else if(madlibCharArray[ind] == 'V') {
           printf("PLease enter a verb: ");
       } else {
           printf("Please enter an adjective: ");
       }
       scanf("%s", &inputArray[ind]);
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
      } else{
          printf("%s", madin);
      }
  }
}




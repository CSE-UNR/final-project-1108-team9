// Waleed Naqshband, Nicole Eames, Sarah Enlow
// 12/10/24
// Purpose: Madlibs Using 2D Arrays for Group Final

#include <stdio.h>

#define SIZE 1024
#define FILE_NAME "madlib1.txt"

int readFileInto2DArray(FILE* filePointer, int row, int col, char array[][col]);
void getWords(int row, char inputArray[SIZE][SIZE]);
void PrintText(int rows, int colm, char strings[][colm]);

int main(){
    FILE* filePointer;
    int row;
    char stringArray[SIZE][SIZE];

    filePointer = fopen(FILE_NAME, "r");
    if (filePointer == NULL) {
        printf("Could not find file.\n");
        return 0;
    }
    row = readFileInto2DArray(filePointer,SIZE, SIZE, stringArray);
    fclose(filePointer);

    getWords(row, stringArray);

    PrintText(row, SIZE, stringArray);

    return 0;
}

int readFileInto2DArray(FILE* filePointer, int row, int col, char array[][col]) {
    int k = 0;
    while (fgets(array[k], col, filePointer) != NULL) {
        k++;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (array[i][j] == '\n') {
                array[i][j] = '\0';
            }
        }
    }
    return k; 
}


//inputArray is string array. madlibCharArray is A N V
void getWords(int row, char inputArray[][SIZE]) {
    int ind;
    for(ind = 0; ind < row; ind ++) {
        if(inputArray[ind][0] == 'N') {
            printf("Please enter a noun: ");
            scanf("%s", inputArray[ind]);
        }
        else if(inputArray[ind][0] == 'V') {
            printf("Please enter a verb: ");
            scanf("%s", inputArray[ind]);
        } 
        else if(inputArray[ind][0] == 'A') {
            printf("Please enter an adjective: ");
            scanf("%s", inputArray[ind]);
        }
    }
}


void PrintText(int rows, int colm, char strings[][colm]) {
	int i;

	for(i = 0; i < rows; i++) {
		if (i > 0 && !(strings[i][0] == '.' || strings[i][0] == ',' || strings[i][0] == '!' || strings[i][0] == '?')) {
			printf(" ");
		}
		printf("%s", strings[i]);
		
	}
	printf("\n");
}
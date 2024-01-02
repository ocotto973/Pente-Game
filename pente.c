#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void formatter(char board[6][6]){
	int i,j;
	char letter;
	 char formatBoard[6][6] = {
	 	{'1','2','3','1','2','3'},
	 	{'4','5','6','4','5','6'},
	 	{'7','8','9','7','8','9'},
	 	{'1','2','3','1','2','3'},
	 	{'4','5','6','4','5','6'},
	 	{'7','8','9','7','8','9'}
	};
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j] == 'R' || board[i][j]=='G'){
				letter = board[i][j];
				formatBoard[i][j] = letter;
			}		
		}
	}
	for(i=0;i<3;i++){
		for(j=3;j<6;j++){
			if(board[i][j] == 'R' || board[i][j]=='G'){
				letter = board[i][j];
				formatBoard[i][j] = letter;
			}
		}
	}
	for(i=3;i<6;i++){
		for(j=0;j<3;j++){
			if(board[i][j] == 'R' || board[i][j]=='G'){
				letter = board[i][j];
				formatBoard[i][j] = letter;
			}
		}
	}
	for(i=3;i<6;i++){
		for(j=3;j<6;j++){
			if(board[i][j] == 'R' || board[i][j]=='G'){
				letter = board[i][j];
				formatBoard[i][j] = letter;
			}
		}		
	}
	printf("   B2      B1\n");
	printf("+-------+-------+\n");
	for (i = 0; i < 6; i++) {
		if (i ==3){
			printf("+-------+-------+\n");
			printf("| ");
		}
		else{
			printf("| ");
		}
		for (j = 0; j < 6; j++) {
			if (j == 3){
				printf("%c", '|');
				printf("%c", ' ');
			}
			printf("%c ", formatBoard[i][j]);
		}
		printf("%c",'|');
	printf("\n");
	}
	printf("+-------+-------+\n");
	printf("   B3      B4\n");



}

void placement(char board[6][6],int block, int position,int redOrGreen){
	int count,i,j;
	char letter;
	count = 1;
	if (redOrGreen == 0){
		letter = 'R';
	}
	else{
		letter = 'G';
	}
	if(block == 1){
		for(i=0;i<3;i++){
			for(j=3;j<6;j++){
				if(count == position){
					board[i][j] = letter;
					i = 3;
					break;
				}	
				count+=1;
			}
		}
	}
	else if(block == 2){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(count == position){
					board[i][j] = letter;
					i = 3;
					break;
				}
				count+=1;
			}
		}
	}
	else if(block == 3){
		for(i=3;i<6;i++){
			for(j=0;j<3;j++){
				if(count == position){
					board[i][j] = letter;
					i = 6;
					break;
				}
				count+=1;
			}
			
		}
	}
	else if(block == 4){
		for(i=3;i<6;i++){
			for(j=3;j<6;j++){
				if(count == position){
					board[i][j] = letter;
					i = 6;
					break;
				}
				count+=1;
			}
		}
	}

}

void clockwise(char board[6][6],int block){
	int i,j;
	char temp[3][3];
	char rotatedTemp[3][3];
	if(block == 1){
		/*Copy contents from board to temp */
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				temp[i][j]= board[i][j+3];
			}
		}
		/*rotate temp 3x3 */
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				rotatedTemp[i][j] = temp[2-j][i];
			}
		}
		/* Copy rotatedtemp to board */
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				board[i][j+3] = rotatedTemp[i][j];
			}
		}
	}
                
	else if(block == 2){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				temp[i][j]=board[i][j];
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				board[i][j]=temp[2-j][i];
			}
		}
	}
	else if(block == 3){
		for(i=3;i<6;i++){
			for(j=0;j<3;j++){
				temp[i-3][j]=board[i][j];
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				rotatedTemp[i][j] = temp[2-j][i];
			}
		}
		for(i=3;i<6;i++){
			for(j=0;j<3;j++){
				board[i][j]=rotatedTemp[i-3][j];
			}
		}
	}
	else if(block == 4){ 
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				temp[i][j]= board[i+3][j+3];	
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				rotatedTemp[i][j]=temp[2-j][i];
			}
		}
		for(i=3;i<6;i++){
			for(j=0;j<3;j++){
				board[i][j+3]=rotatedTemp[i-3][j];
			}
		}

	}
}

void counterclockwise(char board[6][6],int block){
	int i,j;
	char temp[3][3];
	char rotatedTemp[3][3];
	if(block == 1){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				temp[i][j]= board[i][j+3];
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				rotatedTemp[i][j]= temp[j][2-i];   
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				board[i][j+3] = rotatedTemp[i][j];
			}
		}
	}
	else if(block == 2){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				temp[i][j]=board[i][j];
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				board[i][j] = temp[j][2-i];
			}
		}
		
	}
	else if(block == 3){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				temp[i][j] = board[i+3][j];
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				rotatedTemp[i][j] = temp[j][2-i];
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				board[i+3][j] = rotatedTemp[i][j];
			}
		}
	}
	else if(block ==4){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				temp[i][j]=board[i+3][j+3];
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				rotatedTemp[i][j] = temp[j][2-i];
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				board[i+3][j+3]= rotatedTemp[i][j];
			}
		}
	}
}

int fiveInRow(char board[6][6],int redOrGreen){
	int i,j,k,counter;
	char letter;
	if(redOrGreen == 0){
		letter = 'R';
	}
	else{
		letter = 'G';
	}
	/*check for horizontally */
	for(i=0;i<6;i++){
		counter = 0;
		for(j=0;j<6;j++){
			if (board[i][j] == letter){
				counter+=1;
			}
			else{
				counter =0;
			}
			if(counter == 5){
				return 1; /* 1=Found five in a row */
			}
		}
	}
	/*check for vertical */
	for(i=0;i<6;i++){
		counter =0;
		for(j=0;j<6;j++){
			if(board[j][i] == letter){
				counter +=1;
			}
			else{
				counter = 0;
			}
			if(counter == 5){
				return 1;
			}
		}
	}
	/*check for diagonal */
	for (i=0; i<=6 - 5; ++i){
		for (j=0;j <= 6 - 5; ++j) {
			counter = 0;
			for (k = 0; k < 5; ++k) {
				if (board[i + k][j + k] == letter) {
					counter+=1;
				}
			}
			if(counter == 5) {
				return 1;
			}
		}
	}

	for (i = 0; i <= 6 - 5; ++i) {
		for (j = 5; j >= 4; --j) {
			counter = 0;
			for (k = 0; k < 5; ++k) {
				if (board[i + k][j - k] == letter) {
					counter+=1;
				} 
				else {
					break;
				}
			}
			if (counter == 5) {
				return 1;
			}
		}
	}
	return 0; /* 0=Did not find five in a row */
}

int main(int argc, char *argv[]) {
	FILE *fp;
	char line[1024];
	int block;
	int position;
	int blockTurn;
	int turnsPlayed;
	int count;
	int ccw,i;
	/*int i,j; */
	int redOrGreen; /* 0 is Red 1 is Green */
	char board[6][6] = {
		{'1','2','3','1','2','3'},
		{'4','5','6','4','5','6'},
		{'7','8','9','7','8','9'},
		{'1','2','3','1','2','3'},
                {'4','5','6','4','5','6'},
		{'7','8','9','7','8','9'}

	}; /*the board for the game*/
	redOrGreen = 0;
	turnsPlayed = 0;
	if(argc == 1){
		printf("There is no file detected\n");
	}
	
	fp = fopen(argv[1], "r"); /* "r" = open for reading */
	count = 0;
        /* read in one line */
	while(fgets(line, 1023, fp) != NULL) {
		if(turnsPlayed == 36){
			formatter(board);
			printf("It's a tie.\n");
			return 0;
		}
		count = 0;
		for (i = 0; line[i] != '\0'; i++) {
			if (isdigit(line[i])) {
				count+=1;
				if (count == 1) {
					block = line[i] - '0';
				} 
				else if (count == 2) {
					position = line[i] - '0';
				} 
				else if (count == 3) {
					blockTurn = line[i] - '0';
					if(line[i+1] == '+'){
						ccw = 1;
					}
					else{
						ccw = 0;
					}
				}
				if (count >= 3) {
					break;
				}
			}
		}
		if(redOrGreen == 0){
			placement(board,block,position,redOrGreen); /*puts Red on board */
			redOrGreen = 1;
		}
		else{
			placement(board,block,position,redOrGreen); /*puts Green on board */
			redOrGreen = 0;
		}
		if(ccw == 1){
			counterclockwise(board,blockTurn);
		}
		else{
			clockwise(board,blockTurn);
		}
		if(fiveInRow(board,0) == 1 && fiveInRow(board,1) == 1){
			formatter(board);
			printf("It's a tie.\n");
			return 0;
		}
		else if(fiveInRow(board,0) == 1){
			formatter(board);
			printf("Red wins!\n");
			return 0;
		}
		else if(fiveInRow(board,1) == 1){
			formatter(board);
			printf("Green wins!\n");
			return 0;
		}
		turnsPlayed+=1;
		/*printf("\n"); */
	}
	fclose(fp);  /* close the file */
	formatter(board);
	/*
	 *
	for (i = 0; i < 6; i++) {
		if (i ==3){
			printf("- - - - - -\n");
		}
		for (j = 0; j < 6; j++) {
			if (j == 3){
				printf("%c", '|');
			}
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}


	printf("\n");

	*/
	/*The board formatted for output */
	/*formatter(board);*/

	 return 0;
 }

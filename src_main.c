#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "life.h"

/* Be sure to read life.h and the other given source files to understand
 * what they provide and how they fit together.  You don't have to
 * understand all of the code, but you should understand how to call
 * parse_life() and clearterm().
 */

/* This is where your program will start.  You should make sure that it
 * is capable of accepting either one or two arguments; the first
 * argument (which is required) is a starting state in one of the Life
 * formats supported by parse_life(), and the second (which is optional)
 * is a number of generations to run before printing output and stopping.
 *
 * The autograder will always call your program with two arguments.  The
 * one-argument format (as described in the handout) is for your own
 * benefit!
 */
int main(int argc, char *argv[])
{
	if(argc == 2){
		if(parse_life(argv[1]) == NULL){
			return -1;
		}
		else {
			char **matrix = parse_life(argv[1]);
			char **next = parse_life(argv[1]);
			int a = -1;
			while(true){
				a++;
				if( a % 2 == 0){
					for(int j = 0; j < GRIDY; j++){
						for(int i = 0; i < GRIDX; i++){
							int count = 0;
							if(matrix[j][i] == 'X'){
								if(j != 0 && i != 0 && matrix[j - 1][i - 1] == 'X' ){
									count++;
								}
								if(j != 0 && matrix[j-1][i] == 'X'){
									count++;
								}
								if(j != 0 && i + 1 != GRIDX && matrix[j-1][i+1] == 'X'){
									count++;
								}
								if(i != 0 && matrix[j][i-1] == 'X'){
									count++;
								}
								if(i + 1 != GRIDX && matrix[j][i+1] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && i != 0 && matrix[j+1][i-1] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && matrix[j+1][i] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && i + 1 != GRIDX && matrix[j+1][i+1] == 'X'){
									count++;
								}
								if(count == 2 || count == 3){
									next[j][i] = 'X';
								}
								else{
									next[j][i] = ' ';
								}
							}
							else if(matrix[j][i] == ' '){
								if(j != 0 && i != 0 && matrix[j - 1][i - 1] == 'X' ){
									count++;
								}
								if(j != 0 && matrix[j-1][i] == 'X'){
									count++;
								}
								if(j != 0 && i + 1 != GRIDX && matrix[j-1][i+1] == 'X'){
									count++;
								}
								if(i != 0 && matrix[j][i-1] == 'X'){
									count++;
								}
								if(i + 1 != GRIDX && matrix[j][i+1] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && i != 0 && matrix[j+1][i-1] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && matrix[j+1][i] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && i + 1 != GRIDX && matrix[j+1][i+1] == 'X'){
									count++;
								}
								if(count == 3){
									next[j][i] = 'X';
								}
								else{
									next[j][i] = ' ';
								}
							}
						}
					}
					for(int r = 0; r < GRIDY; r++){
						printf("%s\n", next[r]);
					}
					usleep(300000);
					clearterm();
				}
				else if( a % 2 != 0){
					for(int j = 0; j < GRIDY; j++){
						for(int i = 0; i < GRIDX; i++){
							int count = 0;
							if(next[j][i] == 'X'){
								if(j != 0 && i != 0 && next[j - 1][i - 1] == 'X' ){
									count++;
								}
								if(j != 0 && next[j-1][i] == 'X'){
									count++;
								}
								if(j != 0 && i + 1 != GRIDX && next[j-1][i+1] == 'X'){
									count++;
								}
								if(i != 0 && next[j][i-1] == 'X'){
									count++;
								}
								if(i + 1 != GRIDX && next[j][i+1] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && i != 0 && next[j+1][i-1] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && next[j+1][i] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && i + 1 != GRIDX && next[j+1][i+1] == 'X'){
									count++;
								}
								if(count == 2 || count == 3){
									matrix[j][i] = 'X';
								}
								else{
									matrix[j][i] = ' ';
								}
							}
							else if(next[j][i] == ' '){
								if(j != 0 && i != 0 && next[j - 1][i - 1] == 'X' ){
									count++;
								}
								if(j != 0 && next[j-1][i] == 'X'){
									count++;
								}
								if(j != 0 && i + 1 != GRIDX && next[j-1][i+1] == 'X'){
									count++;
								}
								if(i != 0 && next[j][i-1] == 'X'){
									count++;
								}
								if(i + 1 != GRIDX && next[j][i+1] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && i != 0 && next[j+1][i-1] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && next[j+1][i] == 'X'){
									count++;
								}
								if(j + 1 != GRIDY && i + 1 != GRIDX && next[j+1][i+1] == 'X'){
									count++;
								}
								if(count == 3){
									matrix[j][i] = 'X';
								}
								else{
									matrix[j][i] = ' ';
								}
							}
						}
					}
					for(int r = 0; r < GRIDY; r++){
						printf("%s\n", matrix[r]);
					}
					usleep(300000);
					clearterm();
				}
			}
		}
	}
	else if(argc == 3){
		if(parse_life(argv[1]) == NULL){
			return -1;
		}
		else {
			char **matrix = parse_life(argv[1]);
			char **next = parse_life(argv[1]);
			if(*argv[2] == '0'){
				for(int j = 0; j < GRIDY; j++){
					printf("%s\n", matrix[j]);
				}
			}
			else{
				int len = strlen(argv[2]);
				int generation = 0;
				int square(int a, int b) {
					int x  = 1;
					for (int i = 0; i < b; i++) {
						x *= a;
					}
					return x;
				}
				for(int q =0; q < len; q++){
					generation += (argv[2][q] -'0') * square(10, len - (q + 1));
				}
				int a = 0;
				for(a = 0;  a < generation; a++){
					if( a % 2 == 0){
						for(int j = 0; j < GRIDY; j++){
							for(int i = 0; i < GRIDX; i++){
								int count = 0;
								if(matrix[j][i] == 'X'){
									if(j != 0 && i != 0 && matrix[j - 1][i - 1] == 'X' ){
										count++;
									}
									if(j != 0 && matrix[j-1][i] == 'X'){
										count++;
									}
									if(j != 0 && i + 1 != GRIDX && matrix[j-1][i+1] == 'X'){
										count++;
									}
									if(i != 0 && matrix[j][i-1] == 'X'){
										count++;
									}
									if(i + 1 != GRIDX && matrix[j][i+1] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && i != 0 && matrix[j+1][i-1] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && matrix[j+1][i] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && i + 1 != GRIDX && matrix[j+1][i+1] == 'X'){
										count++;
									}
									if(count == 2 || count == 3){
										next[j][i] = 'X';
									}
									else{
										next[j][i] = ' ';
									}
								}
								else if(matrix[j][i] == ' '){
									if(j != 0 && i != 0 && matrix[j - 1][i - 1] == 'X' ){
										count++;
									}
									if(j != 0 && matrix[j-1][i] == 'X'){
										count++;
									}
									if(j != 0 && i + 1 != GRIDX && matrix[j-1][i+1] == 'X'){
										count++;
									}
									if(i != 0 && matrix[j][i-1] == 'X'){
										count++;
									}
									if(i + 1 != GRIDX && matrix[j][i+1] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && i != 0 && matrix[j+1][i-1] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && matrix[j+1][i] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && i + 1 != GRIDX && matrix[j+1][i+1] == 'X'){
										count++;
									}
									if(count == 3){
										next[j][i] = 'X';
									}
									else{
										next[j][i] = ' ';
									}
								}
							}
						}
					}
					else if( a % 2 != 0){
						for(int j = 0; j < GRIDY; j++){
							for(int i = 0; i < GRIDX; i++){
								int count = 0;
								if(next[j][i] == 'X'){
									if(j != 0 && i != 0 && next[j - 1][i - 1] == 'X' ){
										count++;
									}
									if(j != 0 && next[j-1][i] == 'X'){
										count++;
									}
									if(j != 0 && i + 1 != GRIDX && next[j-1][i+1] == 'X'){
										count++;
									}
									if(i != 0 && next[j][i-1] == 'X'){
										count++;
									}
									if(i + 1 != GRIDX && next[j][i+1] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && i != 0 && next[j+1][i-1] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && next[j+1][i] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && i + 1 != GRIDX && next[j+1][i+1] == 'X'){
										count++;
									}
									if(count == 2 || count == 3){
										matrix[j][i] = 'X';
									}
									else{
										matrix[j][i] = ' ';
									}
								}
								else if(next[j][i] == ' '){
									if(j != 0 && i != 0 && next[j - 1][i - 1] == 'X' ){
										count++;
									}
									if(j != 0 && next[j-1][i] == 'X'){
										count++;
									}
									if(j != 0 && i + 1 != GRIDX && next[j-1][i+1] == 'X'){
										count++;
									}
									if(i != 0 && next[j][i-1] == 'X'){
										count++;
									}
									if(i + 1 != GRIDX && next[j][i+1] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && i != 0 && next[j+1][i-1] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && next[j+1][i] == 'X'){
										count++;
									}
									if(j + 1 != GRIDY && i + 1 != GRIDX && next[j+1][i+1] == 'X'){
										count++;
									}
									if(count == 3){
										matrix[j][i] = 'X';
									}
									else{
										matrix[j][i] = ' ';
									}
								}
							}
						}
					}
				}
				if( a % 2 == 0){
					for(int r = 0; r < GRIDY; r++){
						printf("%s\n", matrix[r]);
					}
				}
				else if( a % 2 != 0){
					for(int r = 0; r < GRIDY; r++){
						printf("%s\n", next[r]);
					}
				}
			}
		}
	}
	else{
		printf("error\n");
		return -1;
	}
    return 0;
}

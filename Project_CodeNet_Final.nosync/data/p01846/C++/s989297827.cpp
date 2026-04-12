#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


int main(){

	int row,col,div,count,a,b,c,d;
	char buf[200],table[10][11];

	while(true){
		scanf("%s",buf);
		if(buf[0] == '#')break;

		for(int i = 0; i < 10; i++){
			for(int k = 0; k < 11; k++)table[i][k] = '\0';
		}

		row = 0,col = 0;
		for(int i = 0; buf[i] != '\0';i++){
			if(buf[i] >= '0' && buf[i] <= '9'){
				div = buf[i] - '0';
				for(int k = 0; k < div; k++){
					table[row][col] = ' ';
					col++;
				}
			}else if(buf[i] == 'b'){
				table[row][col] = 'b';
				col++;
			}else{ //buf[i] == '/'
				row++;
				col = 0;
			}
		}

		scanf("%d %d %d %d",&a,&b,&c,&d);
		table[a-1][b-1] = ' ';
		table[c-1][d-1] = 'b';


		for(int h = 0; h <= row; h++){
			for(int w = 0; w < 11; w++){
				if(table[h][w] == ' '){
					count = 0;
					for(int p = w; table[h][p] == ' ';p++){
						count++;
						w++;
					}
					w--;
					printf("%c",'0' + count);
				}else if(table[h][w] == 'b'){
					printf("b");
				}else{ //table[h][w] == '\0'
					if(h != row){
						printf("/");
						break;
					}
				}
			}
		}
		printf("\n");
	}

	return 0;
}
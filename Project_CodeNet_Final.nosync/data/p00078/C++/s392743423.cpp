#include<stdio.h>
int table[15][15];
int main(){
	int a;
	while(scanf("%d",&a),a){
		int row=a/2+1;
		int col=a/2;
		for(int i=0;i<a;i++)
			for(int j=0;j<a;j++)
				table[i][j]=0;
		for(int i=0;i<a*a;i++){
			if(table[row%a][col%a]){
				row++;
				col--;
			}
			table[row%a][col%a]=i+1;
			row++;
			col++;
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				printf("%4d",table[i][j]);
			}
			printf("\n");
		}
	}
}
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int table[15][15],n;

void func(int row,int col,int num){
	if(num > n*n)return;

	if(col < 0){
		func(row,n-1,num);
	}else if(col >= n){
		func(row,0,num);
	}else if(row >=  n){
		func(0,col,num);
	}else if(table[row][col] != 0){
		func(row+1,col-1,num);
	}else{
		table[row][col] = num;
		func(row+1,col+1,num+1);
	}
}

int main(){

	while(true){
		scanf("%d",&n);
		if(n == 0)break;

		for(int i=0; i < n; i++){
			for(int k=0; k < n; k++)table[i][k] = 0;
		}

		table[(n+1)/2][(n-1)/2] = 1;
		func((n+1)/2+1,(n-1)/2+1,2);

		for(int i = 0; i < n; i++){
			for(int k=0; k < n; k++){
				printf("%4d",table[i][k]);
			}
			printf("\n");
		}
	}

	return 0;
}
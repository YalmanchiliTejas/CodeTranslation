#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct{
	int col;
	int row;
}Point;

int main(){

	int in;
	Point now;

	while(cin >> in && in){
		int num = 1;
		int data[in][in];

		for(int i = 0; i < in; i++){
			for(int j = 0; j < in; j++){
				data[i][j] = 0;
			}
		}
	
		now.col = (in-1)/2;
		now.row = (in-1)/2+1;
		data[now.row][now.col] = num;
		now.col++;
		now.row++;

		while(num < in*in){
			if(now.col >= in) now.col = 0;
			if(now.col < 0) now.col = in-1;
			if(now.row >= in) now.row = 0;

			if(data[now.row][now.col] != 0){
				now.col--;
				now.row++;
				continue;
			}
			num++;
			data[now.row][now.col] = num;
			now.col++;
			now.row++;
		}
		for(int i = 0; i < in; i++){
			for(int j = 0; j < in; j++){
				printf("%4d",data[i][j]);
			}
			cout << endl;
		}
	}
	return 0;
}
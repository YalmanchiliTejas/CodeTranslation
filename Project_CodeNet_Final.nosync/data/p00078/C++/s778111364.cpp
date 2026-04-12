#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int data[20][20];

void PrintData(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%4d",data[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int unko1;
	queue<int> tmp;
	while(cin>>unko1){
		if(unko1==0)break;
		tmp.push(unko1);
	}
	tmp.push(0);
	int size=tmp.size();
	for(int unko = 0;unko<size;unko++){
		int n = tmp.front();
		tmp.pop();
		if(n==0)break;

		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				data[i][j]=0;
			}
		}
		
		int cnt = 1;
		int i=n/2+1;
		int j=n/2;
		while(1){
			if(data[i%n][j%n]>0){
				j--;
				i++;
			}
			data[i%n][j%n] = cnt;
			i++;
			j++;
			cnt++;
			if(cnt>n*n){
				break;
			}
		}
		PrintData(n);
	}

	return 0;
}

/*
Sample Input
3
5
0
Output for the Sample Input
   4   9   2
   3   5   7
   8   1   6
  11  24   7  20   3
   4  12  25   8  16
  17   5  13  21   9
  10  18   1  14  22
  23   6  19   2  15
 */
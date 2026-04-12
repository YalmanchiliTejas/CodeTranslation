#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int magicTable[16][16]={0},memo[16][16]={0};
int n,x,y;

int main(void){
	
	while(cin>>n,n){
		
		memset(magicTable,0,sizeof(magicTable));
				
		x=n/2;
		y=n/2+1;
		
		for(int i=1;i<=n*n;i++){
			magicTable[y][x]=i;
			x++;
			y++;
			
			if(y==n){
				y=0;
			}
			if(x==n){
				x=0;
			}
			
			if(magicTable[y][x]!=0){
				x--;
				y++;
				if(y==n){
					y=0;
				}
				if(x==-1){
					x=n-1;
				}
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%4d",magicTable[i][j]);
			}
			printf("\n");
		}
	}
}
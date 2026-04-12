#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
	int H,W;
	scanf("%d %d",&H,&W);
	char a[H][W];
	int exH[H]={};
	int exW[W]={};
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(a[i][j]=='#')break;
			if(j==W-1)exH[i]=1;
		}
	}
	
	for(int i=0;i<W;i++){
		for(int j=0;j<H;j++){
			if(a[j][i]=='#')break;
			if(j==H-1)exW[i]=1;
		}
	}
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(exH[i]==1||exW[j]==1)continue;
			printf("%c",a[i][j]);
			
		}
		if(exH[i]!=1)printf("\n");
	}
	return 0;
}

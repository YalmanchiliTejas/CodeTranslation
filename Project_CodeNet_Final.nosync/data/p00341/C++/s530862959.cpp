#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int m,n,i,j,t,y;
	int e[15]={10000};
	for(i=0;i<12;i++){
		scanf("%d",&e[i]);
	}
	sort(e,e+12);
	
	if(e[0]==e[1] && e[2]==e[3] && e[4]==e[5] && e[6]==e[7] && e[8]==e[9] && e[10] == e[11]){
		printf("yes\n");
	}
	else{
		printf("no\n");
		}
	}
	
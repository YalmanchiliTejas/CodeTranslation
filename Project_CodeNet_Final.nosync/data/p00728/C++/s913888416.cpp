#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n;//3<=n<=100
	int s;//0<=s<=1000
	int max,min,total,result;
	int i,finish=0;
	
	scanf("%d",&n);
	
	while(finish==0){
	max=0;
	min=1000;
	total=0;
	for(i=0;i<n;i++){
		scanf("%d",&s);
		if(s<min){min=s;}
		if(s>max){max=s;}
		total+=s;
	}
	result=(total-min-max)/(n-2);
	printf("%d\n",result);
	
	scanf("%d",&n);
	if(n==0){finish=1;}
	}
	return 0;
}
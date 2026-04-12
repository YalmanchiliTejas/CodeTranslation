#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	unsigned int n;
	scanf("%d",&n);
	if(n<15)
	printf("%d",n*800);
	else if(n>=15&&n<=1000)
	printf("%d",n*800-(200*(n/15)));
	return 0;
}
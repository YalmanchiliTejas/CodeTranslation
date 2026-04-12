#include<stdio.h>
int main(void){
	int n;
	int x;
	int sum;
	scanf("%d",&n);
	x=n/15;
	sum=800*n-200*x;
	printf("%d\n",sum);
	return 0;
}
#include<stdio.h>

int main(void){
	int r,g,b,total;
	
	scanf("%d",&r);
	scanf("%d",&g);
	scanf("%d",&b);
	total=100*r+10*g+b;
	if(total%4==0){
		printf("YES\n");
		}
	else{
		printf("NO\n");
		}
}
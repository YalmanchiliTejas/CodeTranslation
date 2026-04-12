#include<stdio.h>
int main(){
	int A,B,C;
	scanf("%d%d%d",&A,&B,&C);
	puts((A*100+B*10+C)%4==0?"YES":"NO");
	return 0;
}

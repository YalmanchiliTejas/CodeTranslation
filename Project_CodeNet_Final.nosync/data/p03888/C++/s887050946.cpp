#include<stdio.h>

double R1,R2;

int main(void){
	scanf("%lf%lf",&R1,&R2);
	printf("%.10f\n",1/(1/R1+1/R2));
	return 0;
}
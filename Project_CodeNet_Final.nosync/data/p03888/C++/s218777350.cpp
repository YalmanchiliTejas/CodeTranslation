#include<stdio.h>
double a,b;
int main(){
	scanf("%lf%lf",&a,&b);
	double ans=a*b;
	ans/=a+b;
	printf("%.10f",ans);
}
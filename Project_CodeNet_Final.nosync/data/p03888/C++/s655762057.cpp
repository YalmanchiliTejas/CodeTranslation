#include<cstdio>
#include<cstring>
#include<cstdlib>
int main(void){
	double a;
	double b;
	int c;
	double s;
	int x[10000];
	int p;
	int n;
	char d[10000];
	scanf("%lf %lf", &a,&b);
	s = a*b / (a + b);
	printf("%f", s);
	return 0;
}
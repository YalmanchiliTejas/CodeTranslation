#include<cstdio>
int main(){
	int n,x,y,a;
	scanf("%dn",&n);
	x = 800 * n;
	a = n / 15;
	y = a * 200;
	printf("%d\n",x - y);
	return 0;
	}
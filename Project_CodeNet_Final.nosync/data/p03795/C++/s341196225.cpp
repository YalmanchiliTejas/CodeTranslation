#include<cstdio>
int main(){
	int n;
	int x,y;
	scanf("%d",&n);
	x = 800 * n;
	y = (n / 15) * 200;
	printf("%d\n",x-y);
	return 0;
}

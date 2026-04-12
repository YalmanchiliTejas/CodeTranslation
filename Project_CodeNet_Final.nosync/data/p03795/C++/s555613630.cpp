#include <cstdio>

int n, cost;

int main(){
	scanf("%d", &n);
	cost = 800*n;
	cost -= n/15*200;
	printf("%d\n", cost);
	return 0;
}
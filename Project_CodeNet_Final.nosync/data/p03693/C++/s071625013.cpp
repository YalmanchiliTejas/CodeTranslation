#include<cstdio>

int r, g, b;

int main(){
	scanf("%d %d %d", &r, &g, &b);
	int num = 100 * r + 10 * g + b;
	if(num % 4 == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}

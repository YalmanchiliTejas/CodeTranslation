#include <cstdio>

int r, g, b;

int main(){
	scanf("%d %d %d", &r, &g, &b);
	if((100 * r + 10 * g + b) % 4 == 0) printf("YES\n");
	else printf("NO\n");
}
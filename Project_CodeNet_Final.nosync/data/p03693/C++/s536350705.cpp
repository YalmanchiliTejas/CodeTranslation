#include<stdio.h>

int main(void){
	int r, g, b, s;
	scanf("%d %d %d", &r, &g, &b);
	s = r * 100 + g * 10 + b;
	if (s % 4 == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
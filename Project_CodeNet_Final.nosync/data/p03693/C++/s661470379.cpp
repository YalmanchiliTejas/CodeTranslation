#include <cstdio>
int main() {
	int r, g, b, s = 0;
	scanf("%d%d%d", &r, &g, &b);
	s = s * 10 + r;
	s = s * 10 + g;
	s = s * 10 + b;
	if(s%4 == 0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
} 
#include <stdio.h>

int main()
{
	int r;
	int g;
	int b;
	int num;

	scanf("%d %d %d", &r, &g, &b);

	if (r < 0 || r > 9) {
		goto end;
	} else if (g < 0 || g > 9) {
		goto end;
	} else if (b < 0 || b > 9) {
		goto end;
	}

	num = r * 100 + g * 10 + b;

	if (num % 4 == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
end:
	return 0;
}

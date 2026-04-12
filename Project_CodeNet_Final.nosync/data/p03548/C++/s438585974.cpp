#include <stdio.h>

int main(void)
{
	int x, y, z, n,a;
	scanf("%d%d%d", &x, &y, &z);
	n = 1;
	while (1){
		int tmp;
		tmp = (n*y + (n - 1)*z + 2*z);
		a = tmp;
		if (tmp >= x) break;
		else n++;
	}
	if (a > x) n = n - 1;
	printf("%d\n", n);
	return 0;
}
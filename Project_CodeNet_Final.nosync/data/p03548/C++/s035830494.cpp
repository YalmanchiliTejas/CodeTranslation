#include <cstdio>

int main(void)
{
	int x, y, z, ans;
	scanf("%d%d%d", &x, &y, &z);
	for (ans = 0; z * (ans + 1) + y * ans <= x; ans++) ;
	printf("%d\n", ans - 1);
	return 0;
}

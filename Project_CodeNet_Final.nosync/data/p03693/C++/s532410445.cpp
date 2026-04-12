#include<stdio.h>
#include<string.h>
#include<math.h>
//言語は「C++14(GCC 5.4.1)」
//AtCoder Beginner Contest 64-A

int main(void)
{
	int r, g, b, S;
	scanf("%d", &r);
	scanf("%d", &g);
	scanf("%d", &b);
	S = 100 * r + 10 * g + b;
	if (S % 4 == 0)
		printf("YES");
	else
		printf("NO");
	return 0;
}
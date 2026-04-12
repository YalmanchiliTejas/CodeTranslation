#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<string>
#include<vector>

int main(void) {

	int A = 0, B = 0, C = 0, X = 0, Y = 0;
	int ans1 = 0, ans2 = 0,ans3 = 0;

	scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y);
	
	{
		ans1 += (X * 2) * C;
		ans1 += (X > Y ? 0 : Y - X) * B;
	}
	{
		ans2 += (Y * 2) * C;
		ans2 += (Y > X ? 0 : X - Y) * A;
	}
	{
		ans3 += X * A;
		ans3 += Y * B;
	}
	printf("%d\n", (ans1 > (ans2 > ans3 ? ans3 : ans2) ? (ans2 > ans3 ? ans3 : ans2) : ans1));
	return 0;
}
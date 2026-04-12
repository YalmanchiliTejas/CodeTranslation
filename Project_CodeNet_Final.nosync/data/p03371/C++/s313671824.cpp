#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	int X, Y;
	scanf("%d %d", &X, &Y);
	int ans = 0;
	if (A + B >= 2 * C) {
		ans += 2 * C * min(X, Y);
		if (X >= Y) {
			ans += min(A, 2 * C) * (X - Y);
		} else {
			ans += min(B, 2 * C) * (Y - X);
		}
	} else {
		ans += A * X + B * Y;
	}
	printf("%d\n", ans);

	return 0;
}

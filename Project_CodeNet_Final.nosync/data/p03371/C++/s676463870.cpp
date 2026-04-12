#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int a, b, ab, x, y, ans=0;

	scanf("%d %d %d %d %d", &a, &b, &ab, &x, &y);

	if (a + b < ab * 2) {
		printf("%d\n", a * x + b * y);
	}
	else {
		ans += min(x, y) * ab*2;
		int work = (x < y ? x : y);
		x -= work; y -= work;
		if (y > 0) x = y, a = b;
		ans += min(x*a, x*ab*2);
		printf("%d\n", ans);
	}
}
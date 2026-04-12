#include <iostream>
using namespace std;
int main() {
	int a, b, c, x, y;
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	int ans = 1e9;
	for (int i = 0; i <= max(x, y) * 2; i++) {
		int now = c * i + max(0, (x - i / 2) * a) + max(0, (y - i / 2) * b);
		ans = min(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}
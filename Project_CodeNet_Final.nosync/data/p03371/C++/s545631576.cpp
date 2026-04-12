#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a, b, c, x, y;
int ans;

int main() {
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	int sum = a * x + b * y;
	int s = min(x, y) * 2 * c;
	if(x >= y) s += (x - y) * a;
	else s += (y - x) * b;
	int s0 = max(x, y) * 2 * c;
	s = min(s, s0);
	ans = min(sum, s);
	printf("%d\n", ans);
}
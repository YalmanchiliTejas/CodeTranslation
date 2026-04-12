#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int a, b, c, x, y;
	int ans;
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	ans = a * x + b * y;
	for (int i = 0; i <= max(x, y) * 2; i += 2) {
		ans = min(max((x-i/2),0) * a + max((y-i/2),0) * b+i*c, ans);
	}
	printf("%d", ans);
}


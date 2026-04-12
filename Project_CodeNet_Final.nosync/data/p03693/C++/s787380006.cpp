#include <bits/stdc++.h>
using namespace std;



int main() {
	// freopen("input.in", "r", stdin);
	// freopen("output.o", "w", stdout);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int num = 100 * a + 10 * b + c;
	if (num % 4 == 0) {
		puts("YES");
	} else puts("NO");
}
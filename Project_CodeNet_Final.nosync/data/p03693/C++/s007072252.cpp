#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	a = a * 100 + b * 10 + c;
	if(a % 4) printf("NO\n");
	else printf("YES\n");
	return 0;
}

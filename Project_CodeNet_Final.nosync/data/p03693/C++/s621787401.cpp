#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int main() {
	int a,b,c;
	// freopen("a.inp", "r", stdin);
	// freopen("a.out", "w", stdout);
	scanf("%d %d %d", &a, &b , &c);
	int n = a * 100 + b * 10 + c;
	if (n % 4 ==0) printf("YES");
	else printf("NO");
	return 0;
}
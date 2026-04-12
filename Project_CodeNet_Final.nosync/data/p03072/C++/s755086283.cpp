#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	int maxx = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> m;
		if (m >= maxx) {
			maxx = m;
			++ ans;
		}
	}
	printf("%d\n", ans);
	return 0;
} 
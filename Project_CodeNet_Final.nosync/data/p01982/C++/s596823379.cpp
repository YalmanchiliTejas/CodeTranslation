#include <bits/stdc++.h>

using namespace std;

const int N = 50;
int a[N] = { 0 };

int main() {
	int n, l, r, ans, i;
	while(cin >> n >> l >> r, n) {
		ans = 0;
		for(i = 0;i < n;++i) {
			cin >> a[i];
		}
		for(int y = l;y <= r;++y) {
			int i;
			for(i = 0;i < n;++i) {
				if(y % a[i] == 0) {
					ans += (1 - i % 2);
					break;
				}
			}
			if(i == n) {
				ans += (1 - i % 2);
			}
		}
		cout << ans << endl;
	}
	return 0;
}


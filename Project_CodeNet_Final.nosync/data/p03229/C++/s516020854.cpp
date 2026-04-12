#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e5 + 7;
const int Inf = 1 << 30;
int n;
ll a[maxx];

int main() {
	while(cin >> n && n) {
		ll ans = 0;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		int l = 1, r = n;
		ans = abs(a[1] - a[n]);
		for(int i = 2; i <= n / 2; i++) {
			int dd = abs(a[l] - a[n - i + 1]);
			int pp = abs(a[r] - a[i]);
			ans += dd + pp;
			l++;
			r--;
		}
		if(n & 1) {
			int x = abs(a[n / 2 + 1] - a[r]);
			int y = abs(a[n / 2 + 1] - a[l]);
			ans += max(x, y);
		}
		cout << ans << endl;
	}
}
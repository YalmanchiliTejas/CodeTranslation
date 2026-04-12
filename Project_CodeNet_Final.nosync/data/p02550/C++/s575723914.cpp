#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll n, x, m, ans = 0, cnt = 0;
	cin >> n >> x >> m;
	vector<int> f(m);
	bool loop = true;
	while(1) {
		x %= m;
		if (x == 0) break;
		if (x == 1) {
			ans += n - cnt;
			break;
		}
		if (f[x] && loop) {
			ll nx = x, ncnt = 0, sum = 0;
			while(f[nx] != 2) {
				f[nx]++;
				ncnt++;
				sum += nx;
				nx *= nx;
				nx %= m;
			}
			ll r = (n - cnt) / ncnt;
			ans += sum * r;
			cnt += ncnt * r;
			loop = false;
		}
		// 11
		// 12342342342
		// cnt = 4
		else {
			f[x]++;
			ans += x;
			x *= x;
			cnt++;
		}
		if (cnt == n) break;
	}
	cout << ans << endl;
	return 0;
}

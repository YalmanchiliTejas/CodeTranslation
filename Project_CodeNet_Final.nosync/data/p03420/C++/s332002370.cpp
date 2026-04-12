#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MP make_pair
#define sqr(x) ((x) * (x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	fastio;
	#ifdef FlameDragon
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k;
	int ans = 0;
	if (k == 0) {
		cout << n * n << '\n';
		return 0;
	}
	for (int b = k + 1; b <= n; b++) {
		int cnt = (n / b) * (b - k) + (n % b >= k ? n % b - k + 1 : 0ll);
		ans += cnt;
		/*int tcnt = 0;
		for (int a = 1; a <= n; a++) {
			if (a % b >= k) tcnt++;
		}
		cout << b << ' ' << cnt << ' ' << tcnt << '\n';*/
	}
	cout << ans << '\n';
}
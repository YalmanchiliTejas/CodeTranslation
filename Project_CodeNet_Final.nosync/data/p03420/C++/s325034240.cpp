#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << (ll)n * n << endl;
		return 0;
	}
	ll ans = 0;
	for (int b = 1; b <= n; ++b) {
		ll res = n / b;
		ans += res * max(0, b - k);
		ans += max(0, n % b - k + 1);
	}
	cout << ans << endl;
	return 0;
}

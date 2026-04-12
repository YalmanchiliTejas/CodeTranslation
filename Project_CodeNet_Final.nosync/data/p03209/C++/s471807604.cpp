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
	ll n, x;
	cin >> n >> x;
	vector<ll> b(n + 1);
	b[0] = 1;
	rrep(i, n + 1) b[i] = 2 * b[i - 1] + 3;
	vector<ll> p(n + 1);
	p[0] = 1;
	rrep(i, n + 1) p[i] = 2 * p[i - 1] + 1;
	function<long long(long long, long long)> Dfs = [&](long long L, long long now_x) {
		if (L == 0) return 1LL;
		ll ret = 0;
		if (now_x >= 1) now_x--;
		if (now_x >= 1) {
			if (now_x >= b[L - 1]) {
				now_x -= b[L - 1];
				ret += p[L - 1];
			}
			else {
				ret += Dfs(L - 1, now_x);
				now_x = 0;
			}
		}
		if (now_x >= 1) now_x--, ret++;
		if (now_x >= 1) {
			if (now_x >= b[L - 1]) {
				now_x -= b[L - 1];
				ret += p[L - 1];
			}
			else {
				ret += Dfs(L - 1, now_x);
				now_x = 0;
			}
		}
		return ret;
	};
	ll ans = Dfs(n, x);
	cout << ans << endl;
	return 0;
}
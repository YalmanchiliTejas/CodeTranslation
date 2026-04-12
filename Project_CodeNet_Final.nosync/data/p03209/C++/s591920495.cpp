#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

ll n, x;
ll h[52];
ll p[52];
ll j_ans;

ll dfs(ll a, ll b) {
	ll ans = 0;
	if (a == 0) return 1;
	if (b >= 1) b--;
	if (b >= 1) {
		if (b >= h[a - 1]) {
			b -= h[a - 1];
			ans += p[a - 1];
		}
		else {
			ans += dfs(a - 1, b);
			b = 0;
		}
	}
	if (b >= 1) {
		b--;
		ans++;
	}
	if (b >= 1) {
		if (b >= h[a - 1]) {
			b -= h[a - 1];
			ans += p[a - 1];
		}
		else {
			ans += dfs(a - 1, b);
			b = 0;
		}
	}
	if (b >= 1)b--;
	return ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x;
	h[0] = 1;
	rrep(i, n + 1) {
		h[i] = h[i - 1] * 2 + 3;
	}
	p[0] = 1;
	rrep(i, n + 1) {
		p[i] = 2 * p[i - 1] + 1;
	}
	ll ans = dfs(n, x);
	dunk(ans);
	return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
constexpr int INF = 1e9, MOD = 1e9 + 7;
constexpr int64_t LINF = 5e18, LMOD = 998244353;
// #include <atcoder/all>
// using namespace atcoder;
// const int dy[]={0,-1,0,1,1,-1,-1,1};
// const int dx[]={1,0,-1,0,1,1,-1,-1};

int64_t a[200010];
int main() {
	int64_t n; cin >> n;
	int64_t x, m; cin >> x >> m;
	set<pair<int64_t, int64_t>> st;
	a[0] = x;
	st.emplace(x, 0);
	int64_t l = -1, r;
	for(int64_t i = 1; i < n; ++i) {
		x *= x;
		x %= m;
		// cerr << x << '\n';
		a[i] = x;
		auto itr = st.lower_bound({x, 0});
		if(itr != st.end()) {
			if(itr->first == x) {
				l = itr->second;
				r = i - 1;
				break;
			}
		}
		st.emplace(x, i);
	}
	// cerr << l << " " << r << '\n';
	int64_t ans = 0;
	if(l < 0) {
		for(int i = 0; i < n; ++i) {
			ans += a[i];
		}
		cout << ans << '\n';
		return 0;
	}
	for(int i = 0; i < l; ++i) {
		ans += a[i];
	}
	int64_t lo = 0;
	for(int i = l; i <= r; ++i) {
		lo += a[i];
	}
	int64_t cnt = (n - l) / (r - l + 1);
	int64_t mo = (n - l) % (r - l + 1);
	// cerr << cnt << " " << mo << '\n';
	ans += cnt * lo;
	for(int i = 0; i < mo; ++i) {
		ans += a[l + i];
	}
	cout << ans << '\n';
	return 0;
}

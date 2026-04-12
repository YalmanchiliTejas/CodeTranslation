#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
typedef std::vector<ll> vec;
int n;
vec v;
ll ans;
inline void solve(vec & x) {
	ll v = x.back() - n; x.pop_back();
	for(ll & i : x) ++ i;
	x.insert(std::lower_bound(x.begin(), x.end(), v), v);
	++ ans;
}
inline ll _try(vec x) {
	for(int i = 0;i < x.size();++i) {
		ll v = x.back() - n; x.pop_back();
		for(ll & i : x) ++ i;
		if(x.size() && v > x.front()) return -1e18;
		x.insert(x.begin(), v);
	}
	return x.front();
}
inline void big_do(vec & x) {
	for(int j = 0;j < n;++j) {
		// std::cout << (j ? x[j - 1] : 0) + n - j << ' ' <<  _try(vec(x.begin() + j, x.end())) << std::endl;
		if((j ? x[j - 1] : 0) + n - j <= _try(vec(x.begin() + j, x.end()))) {
			const int pre_add = n - j, suf_dec = n - pre_add + 1;
			const ll cnt = (x[j] - (j ? x[j - 1] : 0)) / (pre_add + suf_dec);
			if(pre_add * j - suf_dec * (n - j) != -(n - j)) exit(1);
			ans += cnt * pre_add;
			for(int i = 0;i < j;++i) x[i] += pre_add * cnt;
			for(int i = j;i < n;++i) x[i] -= suf_dec * cnt;
			break;
		}
	}
}
const int S = 50;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		ll x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(;;) {
		if(*std::max_element(v.begin(), v.end()) < n) break;
		static int cnt = 0;
		++cnt % 2 ? big_do(v) : solve(v);
	}
	cout << ans << '\n';
}

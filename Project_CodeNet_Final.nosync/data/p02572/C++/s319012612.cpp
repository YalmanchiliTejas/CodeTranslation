#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<functional>
#include<map>
#include<iomanip>
#include<limits>
#include<unordered_set>
#include<cmath>
#include <numeric>
#include <array>
#include<utility>
#include <complex>
#ifndef CLASS_MODINT
#define CLASS_MODINT

#include <cstdint>

template <std::uint32_t mod>
class modint {
private:
	std::uint32_t n;
public:
	modint() : n(0) {};
	modint(std::int64_t n_) : n((n_ >= 0 ? n_ : mod - (-n_) % mod) % mod) {};
	static constexpr std::uint32_t get_mod() { return mod; }
	std::uint32_t get() const { return n; }
	bool operator==(const modint& m) const { return n == m.n; }
	bool operator!=(const modint& m) const { return n != m.n; }
	modint& operator+=(const modint& m) { n += m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator-=(const modint& m) { n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
	modint& operator*=(const modint& m) { n = std::uint64_t(n) * m.n % mod; return *this; }
	modint operator+(const modint& m) const { return modint(*this) += m; }
	modint operator-(const modint& m) const { return modint(*this) -= m; }
	modint operator*(const modint& m) const { return modint(*this) *= m; }
	modint inv() const { return (*this).pow(mod - 2); }
	modint pow(std::uint64_t b) const {
		modint ans = 1, m = modint(*this);
		while (b) {
			if (b & 1) ans *= m;
			m *= m;
			b >>= 1;
		}
		return ans;
	}
};

#endif // CLASS_MODINT

#ifndef CLASS_FAST_MODINT
#define CLASS_FAST_MODINT

#include <cstdint>

static constexpr std::size_t digit_level = 8 * sizeof(std::uint32_t);
static constexpr std::uint32_t find_inv(std::uint32_t n, int d = 6, std::uint32_t x = 1) {
	return d == 0 ? x : find_inv(n, d - 1, x * (2 - x * n));
}
template <std::uint32_t mod> class fast_modint {
	// Fast Modulo Integer, Assertion: mod < 2^(bits of singlebit - 1) and mod is prime
private:
	std::uint32_t n;
	static constexpr std::uint32_t r2 = (((std::uint64_t(1) << digit_level) % mod) << digit_level) % mod;
	static constexpr std::uint32_t ninv = std::uint32_t(-1) * find_inv(mod);
	std::uint32_t reduce(std::uint64_t x) const {
		std::uint32_t res = (x + std::uint64_t(std::uint32_t(x) * ninv) * mod) >> digit_level;
		return res < mod ? res : res - mod;
	}
public:
	fast_modint() : n(0) {};
	fast_modint(std::uint32_t n_) { n = reduce(std::uint64_t(n_) * r2); };
	static constexpr std::uint32_t get_mod() { return mod; }
	std::uint32_t get() const { return reduce(n); }
	bool operator==(const fast_modint& x) const { return n == x.n; }
	bool operator!=(const fast_modint& x) const { return n != x.n; }
	fast_modint& operator+=(const fast_modint& x) { n += x.n; n -= (n < mod ? 0 : mod); return *this; }
	fast_modint& operator-=(const fast_modint& x) { n += mod - x.n; n -= (n < mod ? 0 : mod); return *this; }
	fast_modint& operator*=(const fast_modint& x) { n = reduce(std::uint64_t(n) * x.n); return *this; }
	fast_modint operator+(const fast_modint& x) const { return fast_modint(*this) += x; }
	fast_modint operator-(const fast_modint& x) const { return fast_modint(*this) -= x; }
	fast_modint operator*(const fast_modint& x) const { return fast_modint(*this) *= x; }
	fast_modint inv() const { return pow(mod - 2); }
	fast_modint pow(std::uint64_t b) const {
		fast_modint ans(1), cur(*this);
		while (b > 0) {
			if (b & 1) ans *= cur;
			cur *= cur;
			b >>= 1;
		}
		return ans;
	}
};

#endif // CLASS_FAST_MODINT
using namespace std;
#pragma region define
//#define M_PI 3.141592653589793238
#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define int long long
#define ll long long
#define vel vector<ll>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp(a,b) make_pair(a,b)
#define pin pair<ll,ll>
#define qin pair<pin,ll>
#define V vector
#define Endl endl
#define veb vector<bool>
#define fcout cout << fixed << setprecision(15)
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) (lower_bound(h.begin(),h.end(),val)-h.begin())
#define upper(h,val) (upper_bound(h.begin(),h.end(),val)-h.begin())
#define vveb V<veb>
#define omajinai cin.tie(0);ios::sync_with_stdio(false);
#define endl "\n"
#define pb push_back
#pragma endregion
#pragma region Inner Class
int root(int x, vel& pa) {
	if (pa[x] == -1) { return x; }
	int ans = root(pa[x], pa); pa[x] = ans;
	return ans;
}
bool mar(int x, int y, vel& pa) {
	x = root(x, pa);
	y = root(y, pa);
	if (x != y) { pa[x] = y; }
	return (x != y);
}
int gcd(int x, int y) {
	if (x < y) { return gcd(y, x); }
	if (y == 0) { return x; }
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	x = abs(x); y = abs(y);
	return x * (y / gcd(x, y));
}
V<ll> dijk(V<V<pin>> way, int st, ll inf) {
	int n = way.size();
	V<ll> dist(n, inf); dist[st] = 0;
	priority_queue<pin, vector<pin>, greater<pin>> pq;
	pq.push(mkp(0, st));
	veb is_checked(n, false);
	while (!pq.empty()) {
		pin x = pq.top(); pq.pop();
		int pot = x.second;
		if (!is_checked[pot]) {
			is_checked[pot] = true;
			for (auto y : way[pot]) {
				ll nex_dist = x.first + y.second;
				int nex_pot = y.first;
				if (dist[nex_pot] > nex_dist) {
					dist[nex_pot] = nex_dist;
					pq.push(mkp(nex_dist, y.first));
				}
			}
		}
	}
	return dist;
}
int inf = 1234567890;
V<V<pin>> make_w(vvel v) {
	int n = v.size();
	V<V<pin>> ret(n);
	rep(i, n) {
		for (int x : v[i]) {
			ret[i].push_back(mkp(x, 1));
		}
	}
	return ret;
}
void make_tree(vvel& chi, V<pin>& par, int n, V<V<pin>>& way) {
	V<ll> dist = dijk(way, 0, inf * inf);
	par = V<pin>(n, mkp(0, 0));
	chi = vvel(n);
	rep(i, n) {
		for (auto nex : way[i]) {
			int pot = nex.first;
			if (dist[pot] > dist[i]) { chi[i].push_back(pot); }
			else { par[i] = mkp(pot, dist[i] - dist[pot]); }
		}
	}
}
void pri(vel& v) {
	if (v.size() == 0) { return; }
	cout << v[0];
	rep(i, v.size() - 1) { cout << " " << v[i + 1]; }
	cout << endl;
	return;
}
vvel disj_min(vel& v) {
	int n = v.size();
	vvel ret(22, vel(n));
	ret[0] = v;
	rep(i, 21) {
		rep(j, n) {
			int nex = j + (1 << i);
			if (nex < n) {
				ret[i + 1][j] = min(ret[i][j], ret[i][nex]);
			}
			else {
				ret[i + 1][j] = ret[i][j];
			}
		}
	}
	return ret;
}
int find_min(vvel& dv, int l, int r) {
	int i = 21;
	while (l + (1 << i) > r) {
		i--;
	}
	while (i >= 0) {
		if (dv[i][l] > dv[i][r - (1 << i)]) {
			l = r - (1 << i);
		}
		else {
			r = l + (1 << i);
		}
		i--;
	}
	return l;
}
V<V<pin>> dbl(V<pin>& v) {
	V<V<pin>> ans(20, V<pin>(v));
	int n = v.size();
	rep(i, 19) {
		rep(j, n) {
			ans[i + 1][j].first = ans[i][ans[i][j].first].first;
			ans[i + 1][j].second = max(ans[i][j].second, ans[i][ans[i][j].first].second);
		}
	}
	return ans;
}
pin lca(int s, int t, int diff, V<V<pin>>& pa) {
	if (diff < 0) { return lca(t, s, -diff, pa); }
	int ans = 0;
	rep(i, 19) {
		if ((diff & (1 << i)) != 0) {
			mmax(ans, pa[i][s].second);
			s = pa[i][s].first;
		}
	}
	for (int i = 19; i >= 0; i--) {
		if (pa[i][s] != pa[i][t]) {
			mmax(ans, pa[i][s].second);
			s = pa[i][s].first;
			mmax(ans, pa[i][t].second);
			t = pa[i][t].first;
		}
	}
	if (s != t) {
		mmax(ans, pa[0][s].second);
		mmax(ans, pa[0][t].second);
		s = pa[0][s].first;
	}
	return mkp(s, ans);
}

vel dx = { 0,0,-1,1,1,-1 };
vel dy = { 1,-1,0,0,1,1 };
#define all(a) a.begin(),a.end()
template<typename T>
void mk_uni(V<T>& a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
#pragma endregion
using mint=modint<1000000007>;
signed main() {
	int n; cin >> n;
	vel a(n);
	mint sum = 0; mint sum2 = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i]; 
		sum2 += a[i] * a[i];
	}
	sum *= sum; sum-=sum2;
  	sum*=mint(2).inv();
	cout << sum.get() << endl;
	return 0;
}

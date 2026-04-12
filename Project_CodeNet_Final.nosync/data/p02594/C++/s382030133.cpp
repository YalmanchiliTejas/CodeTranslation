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
using namespace std;
#pragma region define
#define M_PI 3.141592653589793238
#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp(a,b) make_pair(a,b)
#define pin pair<int,int>
#define qin pair<pin,int>
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
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
vel dijk(V<V<pin>> way, int st, int inf) {
	int n = way.size();
	vel dist(n, inf); dist[st] = 0;
	priority_queue<pin, vector<pin>, greater<pin>> pq;
	pq.push(mkp(0, st));
	veb is_checked(n, false);
	while (!pq.empty()) {
		pin x = pq.top(); pq.pop();
		int pot = x.second;
		if (!is_checked[pot]) {
			is_checked[pot] = true;
			for (auto y : way[pot]) {
				int nex_dist = x.first + y.second;
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
void make_tree(vvel& chi, vel& par, int n, int st) {
	V<V<pin>> way(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		way[a].push_back(mkp(b, 1));
		way[b].push_back(mkp(a, 1));
	}
	vel dist = dijk(way, st, n + 1);
	par = vel(n, -1);
	chi = vvel(n);
	rep(i, n) {
		for (auto nex : way[i]) {
			int pot = nex.first;
			if (dist[pot] > dist[i]) { chi[i].push_back(pot); }
			else { par[i] = pot; }
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
int lca(int s, int t, int diff, V<V<pin>>& pa) {
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
	}
	return ans;
}
void alp(int n, vel& pr) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			pr.push_back(i);
			while (n % i == 0) { n /= i; }
		}
	}
	if (n != 1) { pr.push_back(n); }
}
vel dx = { 0,0,-1,1,1,-1 };
vel dy = { 1,-1,0,0,1,1 };
#define all(a) a.begin(),a.end()
template<typename T>
void mk_uni(V<T>& a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <std::uint_fast64_t Modulus> class modint {
	using u64 = std::uint_fast64_t;

public:
	u64 a;

	constexpr modint(const u64 x = 0) noexcept : a(x% Modulus) {}
	constexpr u64& value() noexcept { return a; }
	constexpr const u64& value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
	constexpr modint& operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint& operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint& operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint& operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
};
#pragma endregion
//using mint = modint<998244353>;
using mint = modint<1000000007>;
using vem = vector<mint>;
using vvem = vector<vem>;
#pragma region mint
mint mpow(mint a, int n) {
	mint ans = 1;
	while (n) {
		if (n & 1) { ans *= a; }
		a *= a; n /= 2;
	}
	return ans;
}
vem kai, inv_kai;
void make_kai(int n) {
	kai = vem(n + 1, 1);
	inv_kai = vem(n + 1, 1);
	rep(i, n) { kai[i + 1] = kai[i] * (i + 1); }
	inv_kai[n] = (mint)1 / kai[n];
	for (int i = n; i > 0; i--) { inv_kai[i - 1] = inv_kai[i] * i; }
}
mint com(int n, int r) {
	if (n < 0 || r < 0 || n < r) { return 0; }
	return kai[n] * inv_kai[r] * inv_kai[n - r];
}
mint per(int n, int r) {
	if (n < 0 || r < 0 || n < r) { return 0; }
	return kai[n] * inv_kai[r];
}
#pragma endregion
int inf = 200001;
int cnt(vel& a,int l) {
	int n = a.size();
	int ans = 0;
	for (auto x : a) {
		ans += (x + l - 1) / l;
	}
	return ans;
}
signed main() {
	omajinai;
	int x; cin >> x;
	if (x >= 30) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }
	return 0;
}

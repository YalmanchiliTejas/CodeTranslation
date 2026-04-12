#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
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
#define M_PI 3.141592653589793238
using namespace std;
long long p9 = 998244353;
long long p1 = 1000000007;
#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define ll long long
#define int long long
#define vel vector<ll>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp(a,b) make_pair(a,b)
#define pin pair<ll,ll>
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
#define all(v) v.begin(),v.end()
vel kai;
vel inv_kai;
vel inv;
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
int lcm(ll x, ll y) {
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
void make_inv(int max_inv, int p) {
	inv = vel(max_inv + 1, 1);
	for (int i = 2; i <= max_inv; i++) {
		inv[i] = p - ((p / i) * inv[p % i]) % p;
	}
}
void make_kai(int max_kai, int p) {
	kai = vel(max_kai + 1, 1);
	inv_kai = kai;
	make_inv(max_kai, p);
	rep(i, max_kai) {
		kai[i + 1] = kai[i] * (i + 1); kai[i + 1] %= p;
		inv_kai[i + 1] = inv_kai[i] * inv[i + 1]; inv_kai[i + 1] %= p;
	}
}
int com(int n, int r,int p) {
	if ((n < 0) || (r < 0) || (r > n)) { return 0; }
	int ans = (kai[n] * inv_kai[r]) % p;
	return (ans * inv_kai[n - r]) % p;
}
int per(int n, int r,int p) {
	if ((n < 0) || (r < 0) || (r > n)) { return 0; }
	return (kai[n] * inv_kai[n - r]) % p;
}
vel uni(vel x) {
	if (x.size() == 0) { return x; }
	sor(x);
	int n = x.size();
	vel ans(1, x[0]);
	for (int j = 1; j < n; j++) {
		if (x[j - 1] != x[j]) { ans.push_back(x[j]); }
	}
	x = ans;
	return x;
}
vel dijk(V<V<pin>>& way, int st, int inf) {
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
V<V<pin>> way;
void make_tree(vvel& chi, vel& par,vel &dep,int n) {
	way = V<V<pin>>(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		way[a].push_back(mkp(b, 1));
		way[b].push_back(mkp(a, 1));
	}
	vel dist = dijk(way,0, n + 1);
	par = vel(n, -1);
	chi = vvel(n);
	rep(i, n) {
		for (auto nex : way[i]) {
			int pot = nex.first;
			if (dist[pot] > dist[i]) { chi[i].push_back(pot); }
			else { par[i] = pot; }
		}
	}
	dep = dist;
}
void pri(vel& v) {
	if (v.size() == 0) { return; }
	cout << v[0];
	rep(i, v.size() - 1) { cout << " " << v[i + 1]; }
	cout << endl;
	return;
}
int modpow(int a, int n, int p) {
	if (n == 0) { return 1; }
	int m = n / 2;
	int x = modpow(a, n / 2, p);
	x *= x; x %= p;
	if (n % 2 == 1) { x *= a; x %= p; }
	return x;
}
vel dx = { 0,0,-1,1 };
vel dy = { 1,-1,0,0 };
vel sl(vel& g, int x) {
	vel ans;
	auto itr = upper_bound(all(g), x);
	if (itr != g.end()) { ans.push_back(*itr); }
	if (itr != g.begin()) { itr--; ans.push_back(*itr); }
	return ans;
}
#define sq(n) ((n)*(n))
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
vvel disj_max(vel& v) {
	int n = v.size();
	vvel ret(22, vel(n));
	ret[0] = v;
	rep(i, 21) {
		rep(j, n) {
			int nex = j + (1 << i);
			if (nex < n) {
				ret[i + 1][j] = max(ret[i][j], ret[i][nex]);
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
	return min(dv[i][l], dv[i][r - (1 << i)]);
}
int find_max(vvel& dv, int l, int r) {
	int i = 21;
	while (l + (1 << i) > r) {
		i--;
	}
	return max(dv[i][l], dv[i][r - (1 << i)]);
}
/*void pri(vel& v) {
	if (v.size() == 0) { return; }
	cout << v[0];
	rep(i, v.size() - 1) { cout << " " << v[i + 1]; }
	cout << endl;
	return;
}*/
vvel dbl(vel& v) {
	vvel ans(20, vel(v));
	int n = v.size();
	rep(i, 19) {
		rep(j, n) {
			ans[i + 1][j] = ans[i][ans[i][j]];
		}
	}
	return ans;
}
int lca(int s, int t, int diff, vvel& pa) {
	if (diff < 0) { return lca(t, s, -diff, pa); }
	rep(i, 19) {
		if ((diff & (1 << i)) != 0) {
			s = pa[i][s];
		}
	}
	for (int i = 19; i >= 0; i--) {
		if (pa[i][s] != pa[i][t]) {
			s = pa[i][s];
			t = pa[i][t];
		}
	}
	if (s != t) {
		s = pa[0][s];
	}
	return s;
}
int solve(vel& p) {
	int n = p.size();
	vel u;
	vel d;
	int ans = 0;
	rep(i, n) {
		while (!d.empty()) {
			if (p[d.back()] > p[i]) { d.pop_back(); }
			else { break; }
		}
		while (!u.empty()) {
			if (p[u.back()] < p[i]) { u.pop_back(); }
			else { break; }
		}
		if (!u.empty()) {
			ans += d.end() - lower_bound(all(d), u.back());
		}
		else { ans += d.size(); }
		if (!d.empty()) {
			ans += u.end() - lower_bound(all(u), d.back());
		}
		else { ans += u.size(); }
		d.push_back(i);
		u.push_back(i);
	}
	return ans;
}
#define ui long long
#define bs bitset<501>
#define ui long long
#define ui long long
ui p = 1000000009;
ui modpow(ui a, ui n) {
	if (n == 0) { return 1; }
	long long x = modpow(a, n / 2); x *= x; x %= p;
	if (n % 2 == 1) { x *= a; x %= p; }
	return x;
}
int inf = 1e10;
int sl1(V<pin>& xy,int mn,int mx) {
	set<pin> se;
	int n = xy.size();
	int ans = inf;
	rep(i, n) { se.insert(mkp(xy[i].first, i)); }
	while (true) {
		auto itr1 = se.begin();
		int val = (*itr1).first;
		int pot = (*itr1).second;
		auto itr2 = se.end(); itr2--;
		mmin(ans,(*itr2).first - (*itr1).first);
		if (val == xy[pot].second) { break; }
		se.erase(itr1);
		se.insert(mkp(xy[pot].second, pot));
	}
	return ans * (mx - mn);
}
int sl2(V<pin>& xy,int mn,int mx) {
	int qmx = mn;
	int qmn = mx;
	int n = xy.size();
	rep(i, n) { mmax(qmx, xy[i].first); }
	rep(i, n) { mmin(qmn, xy[i].second); }
	return (qmx - mn) * (mx - qmn);
}
signed main() {
	int n; cin >> n;
	V<pin> xy(n);
	int M = 0; int m = inf;
	rep(i, n) {
		int a, b; cin >> a >> b;
		if (a > b) { swap(a, b); }
		xy[i] = mkp(a, b);
		mmin(m, a); mmax(M, b);
	}
	cout << min(sl1(xy,m,M), sl2(xy,m,M)) << endl;
	return 0;
}
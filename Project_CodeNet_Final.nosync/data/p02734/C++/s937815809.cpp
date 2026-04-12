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
//long long p = 998244353;
long long p = 1000000007;
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
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define fcout cout << fixed << setprecision(15)
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) (lower_bound(h.begin(),h.end(),val)-h.begin())
#define upper(h,val) (upper_bound(h.begin(),h.end(),val)-h.begin())
vel kai;
vel inv_kai;
int rui(int a, int n, int mod) {
	if (n == 0) { return 1 % mod; }
	int x = rui(a, n / 2, mod);
	x *= x; x %= mod;
	if (n % 2 == 1) { x *= a; x %= mod; }
	return x;
}
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
	return x * y / gcd(x, y);
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
void make_kai(int max_kai) {
	kai = vel(max_kai, 1);
	inv_kai = kai;
	rep(i, max_kai - 1) {
		kai[i + 1] = kai[i] * (i + 1); kai[i + 1] %= p;
		inv_kai[i + 1] = modinv(kai[i + 1], p);
	}
}
int com(int n, int r) {
	if ((n < 0) || (r < 0) || (r > n)) { return 0; }
	int ans = (kai[n] * inv_kai[r]) % p;
	return (ans * inv_kai[n - r]) % p;
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
void pr(vel& v) {
	int n = v.size();
	if (n != 0) {
		cout << v[0];
		rep(i, n - 1) {
			cout << " " << v[i + 1];
		}
		cout << endl;
	}
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
vel mul(vel& a, vel& b) {
	int n = a.size();
	int m = b.size();
	vel ans(n + m - 1, 0);
	rep(i, n) {
		rep(j, m) {
			ans[i + j] += a[i] * b[j];
			ans[i + j] %= p;
		}
	}
	return ans;
}
vel rui_p(vel& a, int n) {
	if (n == 0) { return { 1 }; }
	vel qans = rui_p(a, n / 2);
	qans = mul(qans, qans);
	if (n % 2 == 1) {
		qans = mul(qans, a);
	}
	return qans;
}
bool is_prime(int n) {
	if (n == 0 || n == 1) { return false; }
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) { return false; }
	}
	return true;
}
#define bs bitset<50>
void per(int& ans) {
	ans %= p;
	if (ans < 0) { ans += p; }
}
#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define mat V<V<pin>>
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
void pri(vel& v) {
	if (v.size() == 0) { return; }
	cout << v[0];
	rep(i, v.size() - 1) { cout << " " << v[i + 1]; }
	cout << endl;
	return;
}
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
int sz = 1024 * 1024;
vel bit(sz + 1, 0);
void add(int a, int w) {
	while (a <= sz) {
		bit[a] += w;
		a += (a & (-a));
	}
}
int sum(int a) {
	int ans = 0;
	while (a != 0) {
		ans += bit[a];
		a -= (a & (-a));
	}
	return ans;
}
#define vveb V<veb>
#define omajinai cin.tie(0);ios::sync_with_stdio(false);
#define endl "\n"
int modpow(int a, int n, int p) {
	if (n == 0) { return 1; }
	int m = n / 2;
	int x = modpow(a, n / 2, p);
	x *= x; x %= p;
	if (n % 2 == 1) { x *= a; x %= p; }
	return x;
}
bool solve(int i, int j, string& s) {
	string t = s;
	reverse(t.begin() + i, t.begin() + j);
	return s == t;
}
signed main() {
	int n, s; cin >> n >> s;
	vel a(n);
	rep(i, n) { cin >> a[i]; }
	p = 998244353;
	int ans = 0;
	vel cnt(s + 1, 0); cnt[0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for(int j=s-a[i];j>0;j--) {
			cnt[j + a[i]] += cnt[j];
			cnt[j + a[i]] %= p;
		}
		if (a[i] <= s) {
			cnt[a[i]] += n - i;
		}
		ans += cnt[s];
		ans %= p;
	}
	cout << ans << endl;
	return 0;
}

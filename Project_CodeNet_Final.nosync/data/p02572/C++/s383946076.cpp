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

signed main() {
	int p = 1000 * 1000 * 1000 + 7;
	int n; cin >> n;
	vel a(n);
	int sum = 0; int sum2 = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i]; sum %= p;
		sum2 += a[i] * a[i]; sum2 %= p;
	}
	sum *= sum; sum += p - sum2; sum %= p;
	if (sum % 2 == 1) { sum += p; }
	cout << sum / 2 << endl;
	return 0;
}

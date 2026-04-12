#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
const int mn = 1 << 18;
int nn; ll dat[2 * mn - 1],lazy[2 * mn - 1];
void init(int n) {
	nn = 1;
	while (nn < n)nn *= 2;
}
//遅延
void eval(int k, int l, int r) {
	dat[k] += lazy[k];
	if (r - l > 1) {
		lazy[2 * k + 1] += lazy[k];
		lazy[2 * k + 2] += lazy[k];
	}
	lazy[k] = 0;
}
//範囲加算
void update(ll x, int a, int b, int k, int l, int r) {
	eval(k, l, r);
	if (r <= a || b <= l)return;
	if (a <= l && r <= b) {
		lazy[k] += x;
		eval(k, l, r);
	}
	else {
		update(x, a, b, k * 2 + 1, l, (l + r) / 2);
		update(x, a, b, k * 2 + 2, (l + r) / 2, r);
		dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}
ll query(int a, int b, int k, int l, int r) {
	eval(k, l, r);
	if (r <= a || b <= l)return -INF;
	if (a <= l && r <= b)return dat[k];
	else {
		ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
}
vector<LP> v[1 << 18];
int n, m;
ll dp[1 << 18];
int main() {
	cin >> n >> m; init(n+2);
	rep(i, m) {
		int l, r; ll a; cin >> l >> r >> a;
		v[l].push_back({ l,a });
		v[r + 1].push_back({ l,-a });
	}
	ll ans = 0;
	rep1(i, n + 1) {
		rep(j, v[i].size()) {
			int id = v[i][j].first;
			update(v[i][j].second, 0, id, 0, 0, nn);
		}
		dp[i] = query(0, i, 0, 0, nn);
		ans = max(ans, dp[i]);
		update(dp[i], i, i + 1, 0, 0, nn);
	}
	cout << ans << endl;
	//stop
	return 0;
}
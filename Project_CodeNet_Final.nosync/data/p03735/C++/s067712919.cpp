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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
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
LP m[200000] = {};
int main() {
	int n; cin >> n;
	rep(i, n) {
		ll x, y; cin >> x >> y;
		if (x > y)swap(x, y);
		m[i] = { x,y };
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	sort(m, m + n);
	ll a = m[0].first;
	ll b;int chk; b = -1;
	rep(i, n) {
		if (b <= m[i].second) {
			b = m[i].second; chk = i;
		}
	}
	if (chk == 0) {
		ll mi = (ll)MOD;
		ll ma = 0;
		rep(i, n) {
			ma = max(ma, m[i].first);
			mi = min(mi, m[i].second);
		}
		cout << (ma - a)*(b - mi) << endl;
	}
	else {
		ll out = INF;
		ll mi = (ll)MOD;
		ll ma = 0;
		rep(i, n) {
			ma = max(ma, m[i].first);
			mi = min(mi, m[i].second);
		}
		out = min(out, (ma - a)*(b - mi));
		ll out2 = INF;
		ll mi3 = min(m[0].second, m[chk].first);
		ll ma3 = max(m[0].second, m[chk].first);
		ll mi2 = m[1].first; ll ma2 = m[n - 1].first;
		out2 = min(out2, max(ma2, ma3) - min(mi2, mi3));
		rep(i, n) {
			if (i == 0 || i == chk)continue;
			mi3 = min(mi3, m[i].second);
			ma3 = max(ma3, m[i].second);
			if (i < n - 1) {
				mi2 = min(mi3, m[i + 1].first);
			}
			else {
				mi2 = mi3;
			}
			ma2 = max(m[n - 1].first, ma3);
			out2 = min(out2, ma2 - mi2);
		}
		out2 *= (b - a);
		cout << min(out, out2) << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <climits>
#include <cstdlib>
using namespace std;

#define reep(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) reep((i),0,(n))
#define F first
#define S second
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define PB push_back
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
const int INF = INT_MAX / 2;
const ll INFL = LLONG_MAX / 2;
map<string, int> item;
vector<pii> v;
vector<pii> pos;
vector<vector<pii>> shop;
int main() {
	int n, m, W, T;
	cin >> n >> m >> W >> T;
	v = vector<pii>(m);
	rep(i, m) {
		string s;
		pii a;
		cin >> s >> a.F >> a.S;
		item[s] = i;
		v[i] = a;
	}
	shop = vector<vector<pii>>(n);
	pos = vector<pii>(n);
	rep(i, n) {
		int L, x, y;
		cin >> L >> x >> y;
		pos[i] = pii(x, y);
		rep(j, L) {
			string s;
			int t;
			cin >> s >> t;
			shop[i].PB(pii(item[s], v[item[s]].S - t));
		}
	}
	vector<vector<int>> ti(1 << n, vector<int>(n, INF));
	ti[0][0] = 0;
	rep(i, n) {
		ti[1 << i][i] = abs(pos[i].F) + abs(pos[i].S);
	}
	rep(i, 1 << n) {
		rep(j, n) {
			if(ti[i][j] == INF) continue;
			if(!(i & (1 << j))) continue;
			// cout<<i<<" "<<j<<endl;
			rep(k, n) {
				if(i & (1 << k)) continue;
				mins(ti[i + (1 << k)][k], ti[i][j] + abs(pos[j].F - pos[k].F) + abs(pos[j].S - pos[k].S));
			}
		}
	}
	vector<ll> val(1 << n, 0);
	rep(i, 1 << n) {
		vector<pii> tmp;
		rep(j, n) {
			if(i & (1 << j)) {
				for(auto x : shop[j]) {
					tmp.PB(x);
				}
			}
		}
		vector<ll> w(W + 1, 0);
		rep(j, W) {
			for(auto x : tmp) {
				if(j + v[x.F].F > W) continue;
				maxs(w[j + v[x.F].F], w[j] + x.S);
			}
		}
		rep(j, W + 1) {
			maxs(val[i], w[j]);
		}
	}
	vector<pll> w(1 << n);
	vector<ll> res(T + 1, 0);
	ll ans = 0;
	rep(i, 1 << n) {
		if(!i) w[i] = pll(0, 0);
		else {
			ll t = INFL;
			rep(j, n) {
				mins(t, 0LL + ti[i][j] + abs(pos[j].F) + abs(pos[j].S));
			}
			w[i] = pll(t, val[i]);
			// cout<<i<<" "<<t<<" "<<val[i]<<endl;
		}
	}
	rep(i, T) {
		rep(j, w.size()) {
			if(i + w[j].F > T) continue;
			maxs(res[i + w[j].F], res[i] + w[j].S);
		}
	}
	rep(i, T + 1) maxs(ans, res[i]);
	cout << ans << endl;
}
#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

struct UFT{ //O(loga(n))
    int n;
    vi d, r;
    UFT(int n) : n(n), d(n, -1), r(n, 0){};
    int root(int i){
        if(d[i] < 0) return i;
        return d[i] = root(d[i]);
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
 
        if(r[x] < r[y]) swap(x, y);
        else if(r[x] == r[y]) r[x]++;
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    int size(int i){
        return -d[root(i)];
    }
};

struct Edge
{
	int from, to, cost;
};
vector<Edge> es;
typedef pair<pii, int> P;

int main(){
	int n;
	cin >> n;
	vi x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<pair<pii, int>> v(n);
	rep(i, n) v[i].fi = {x[i], y[i]}, v[i].se = i;
	sort(all(v), [&](P a, P b){return a.fi.fi < b.fi.fi;});
	rep(i, n-1) {
		es.pb({v[i].se, v[i+1].se, v[i+1].fi.fi-v[i].fi.fi});
	}
	sort(all(v), [&](P a, P b){return a.fi.se < b.fi.se;});
	rep(i, n-1) {
		es.pb({v[i].se, v[i+1].se, v[i+1].fi.se-v[i].fi.se});
	}
	UFT uf(n);
	sort(all(es), [&](Edge a, Edge b){return a.cost<b.cost;});
	ll ans = 0LL;
	for(auto& e : es) {
		if(uf.same(e.from, e.to)) continue;
		//cout << e.from << " " << e.to <<" " << e.cost << endl;
		ans += e.cost;
		uf.unite(e.from, e.to);
	}
	cout << ans << endl;
}

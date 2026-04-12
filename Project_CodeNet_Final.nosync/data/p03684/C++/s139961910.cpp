#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
ll x[maxn], y[maxn];



//1-indexed DSU
struct DSU {
    int n;
    vector<int> siz, par;
    int init_calls;
    DSU() {
	init_calls = 0;
    }
    void init(int n) {
	assert(++init_calls == 1);
	this->n=n;
	siz.resize(n+10, 1);
	par.resize(n+10);
	for (int i=1; i<=n; i++) par[i] = i;
    }
    int parent(int x) {
	assert(init_calls == 1);
	assert(x>=1 && x<=n);
	if (x == par[x]) return x;
	return par[x] = parent(par[x]);
    }
    bool join(int x, int y) {
	assert(init_calls == 1);
	x = parent(x);
	y = parent(y);
	if (x == y) return false;
	if (siz[x]<siz[y]) swap(x,y);
	par[y] = x;
	siz[x] += siz[y];
	return true;
    }
    void clear() {
	init_calls = 0;
	n = 0;
	siz.clear();
	par.clear();
    }
};


ll dist(pair<int,int> p) {
    int i = p.first;
    int j = p.second;
    return min(abs(x[i]-x[j]), abs(y[i]-y[j]));
}





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;

    for (int i=1; i<=n; i++) {
	cin>>x[i]>>y[i];
    }

    DSU dsu;
    dsu.init(n);
    vector<pair<ll,pair<ll,ll>>> edges;

    {   
	vector<pair<ll,ll>> v;
	for (int i=1; i<=n; i++) {
	    v.push_back({x[i],i});
	}
	sort(v.begin(), v.end());
	for (int i=1; i<n; i++) {
	    ll a = v[i-1].second;
	    ll b = v[i].second;
	    ll wei = v[i].first-v[i-1].first;
	    edges.push_back({wei,{a,b}});
	}
    }

    {
        vector<pair<ll,ll>> v;
	for (int i=1; i<=n; i++) {
	    v.push_back({y[i],i});
	}
	sort(v.begin(), v.end());
	for (int i=1; i<n; i++) {
	    ll a = v[i-1].second;
	    ll b = v[i].second;
	    ll wei = v[i].first-v[i-1].first;
	    edges.push_back({wei,{a,b}});
	}
    }


    sort(edges.begin(), edges.end());
    ll res=0;
    for (auto p: edges) {
	int a = p.second.first;
	int b = p.second.second;
	if (dsu.join(a,b)) {
	    res += p.first;
	}
    }

    out(res);

    return 0;
}

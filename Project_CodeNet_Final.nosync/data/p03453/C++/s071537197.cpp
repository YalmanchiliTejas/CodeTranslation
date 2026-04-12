#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

void add(ll& x, ll y) {
    if (x>=mod) x%=mod;
    if (y>=mod) y%=mod;
    x += y;
    if (x>=mod) x%=mod;
}

const int maxn = 1e6 + 5;

void spa(vector<vector<pair<ll,int>>> g, vector<ll>& dist, vector<ll>& ways, int src) {
    int n = g.size();
    dist.assign(n, inf);
    dist[src] = 0;
    ways.assign(n, 0);
    ways[src] = 1;

    priority_queue<pair<ll,int>> pq;
    pq.emplace(0, src);

    while (pq.size()) {
	auto cur = pq.top();
	pq.pop();
	int at = cur.second;
	ll walk = -cur.first;
	if (walk > dist[at]) {
	    continue;
	}
	for (auto ed: g[at]) {
	    ll wei = ed.first;
	    int to = ed.second;
	    if (walk+wei < dist[to]) {
		ways[to] = ways[at];
		dist[to] = walk+wei;
		pq.emplace(-dist[to], to);
	    } else if (walk+wei == dist[to]) {
		add(ways[to], ways[at]);
	    }
	}
    }
    
}


int n, m, s, t;
vector<vector<pair<ll,int>>> g;
vector<ll> sdist, tdist, sways, tways;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m>>s>>t;
    --s; --t;
    assert(s != t);
    
    g.resize(n);
    sdist.resize(n);
    sways.resize(n);
    tdist.resize(n);
    tways.resize(n);

    for (int i=0; i<m; i++) {
	int u,v,d; cin>>u>>v>>d;
	--u; --v;
	g[u].push_back({d,v});
	g[v].push_back({d,u});
    }

    spa(g, sdist, sways, s);
    spa(g, tdist, tways, t);

    assert(sdist[t] == tdist[s]);
    assert(sways[t] == tways[s]);

    
    ll dist = sdist[t];
    ll ways = sways[t]*sways[t]%mod;


    for (int i=0; i<n; i++) {
	if (i==s || i==t) {
	    continue;
	}
	
	// there exists a shortest path that goes through node i
	if (sdist[i]==dist/2 && tdist[i]==dist/2 && sdist[i]+tdist[i]==dist) {
	    ll paths = sways[i]*tways[i]%mod;
	    ll pairs = paths*paths%mod;
	    //cout<<i<<": "<<paths<<endl;
	    ways -= pairs;
	    ways %= mod;
	}
    }


    for (int u=0; u<n; u++) {
	for (auto ed: g[u]) {
	    int v = ed.second;
	    ll wei = ed.first;
	    if (sdist[u]*2<dist && tdist[v]*2<dist && sdist[u]+wei+tdist[v]==dist) {
		// there exists a shortest path via u-v edge
		ll paths = sways[u]*tways[v]%mod;
		ll pairs = paths*paths%mod;
		ways -= pairs;
		ways %= mod;
	    }
	}
    }

    ways %= mod;
    ways += mod;
    ways %= mod;
    cout<<ways<<endl;
    
    return 0;
}

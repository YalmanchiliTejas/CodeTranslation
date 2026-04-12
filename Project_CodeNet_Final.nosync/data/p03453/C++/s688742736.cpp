#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

const ll INF = 0x1fffffffffffffffLL;

template <typename T>
void make_adjacent(int nV, vector<pair<ii,T>>& arcs, vector<vector<pair<int,T>>>& adj) {
	adj.resize(nV);
	for (pair<ii, T> p: arcs) {
		int u = p.first.first, v = p.first.second;
		assert(u != v);
		T distance = p.second;
		adj[u].push_back(make_pair(v, distance));
		adj[v].push_back(make_pair(u, distance));
	}
}

template <typename T, typename C>
void dij1c(int nV, vector<vector<pair<int,T>>>& adjacent, vector<pair<T,C>>& d, int start) {
	d.assign(nV, make_pair(INF, 0));
	d[start].first = 0;

	priority_queue<pair<T, int>> Q;
	Q.push(make_pair(0, start));

	vector<bool> visited(nV, false);
    vi topo_order;
    topo_order.reserve(nV);
    vector<vi> prevs(nV);

	while (!Q.empty()) {
		T du = -Q.top().first;
		int u = Q.top().second;
        Q.pop();

        if (d[u].first < du) continue;
		if (!visited[u]) {
            topo_order.pb(u);
    		visited[u] = true;
        }

        for (auto p : adjacent[u]) {
            int v = p.first;
            T distance = p.second;

			T alt = du + distance;
			if (alt < d[v].first) {
				d[v].first = alt;
                prevs[v] = vi { u };
				Q.push(make_pair(-alt, v));
            } else if (alt == d[v].first) {
                prevs[v].pb(u);
            }
        }
	}

    for (int v : topo_order) {
        if (v == start) {
            d[v].second = 1;
            continue;
        }
        for (int u : prevs[v]) {
            d[v].second = ADD(d[v].second, d[u].second);
        }
    }
}



class Solver {
    int N, M;
    int S, T;
    vector<int> u, v;
    vector<ll> d;
    ll answer;

 public:
    Solver() {}

 public:
    void input() {
        scanf("%d %d", &N, &M);
        scanf("%d %d", &S, &T);
        u.resize(M);
        v.resize(M);
        d.resize(M);
        rep(i,M) {
            scanf("%d %d %lld", &u[i], &v[i], &d[i]);
        }
        normalize();
    }
    void normalize() {
        --S;
        --T;
        rep(i,M){
            --u[i];
            --v[i];
        }
    }
    void output() {
        printf("%lld\n", answer);
    }
    void solve() {
        vector<pair<ii,ll>> arcs(M);
        rep(i,M){
            arcs[i] = make_pair(ii(u[i],v[i]), d[i]);
        }
        vector<vector<pair<int,ll>>> adj;
        make_adjacent(N, arcs, adj);
        vector<pair<ll,ll>> dS, dT;
        dij1c(N, adj, dS, S);
        dij1c(N, adj, dT, T);
        ll best_time = dS[T].first;
        assert(dS[T] == dT[S]);
        answer = POW(dS[T].second, 2);

        rep(x,N){
            if (x == S || x == T) continue;
            ll sx = dS[x].first, tx = dT[x].first;
            if (sx == tx && sx + tx == best_time) {
                ll cnt = MUL(dS[x].second, dT[x].second);
                answer = SUB(answer, MUL(cnt,cnt));
            }
        }

        rep(i,M){
            rep(j,2) {
                ll su = dS[u[i]].first, tv = dT[v[i]].first;
                if (su + d[i] + tv == best_time
                    && IN(best_time, su*2+1, (su+d[i])*2-1)) {
                    ll cnt = MUL(dS[u[i]].second, dT[v[i]].second);
                    answer = SUB(answer, MUL(cnt,cnt));
        #ifdef DEBUG
                    if (N < 100 && M < 100) {
                        fprintf(stderr, " S - %d <%d> %d - T: %lld\n", u[i],i,v[i], cnt);
                        fprintf(stderr, "  { su=%lld, d=%lld, tv=%lld; best=%lld; best/2 in (%lld, %lld)? \n",
                            su, d[i], tv, best_time, su, (su+d[i]));
                    }
        #endif
                }
                swap(u[i], v[i]);
            }

        }
    }

};

int main() {
    Solver *s = new Solver();
    s->input();
    s->solve();
    s->output();
    delete s;
    return 0;
}

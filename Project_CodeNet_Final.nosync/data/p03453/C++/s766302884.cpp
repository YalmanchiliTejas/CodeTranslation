#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

ll ad(ll a, ll b) { return (a+b)%MOD; }
ll sub(ll a, ll b) { return (a-b+MOD)%MOD; }
ll mul(ll a, ll b) { return a*b%MOD; }

int N,M,S,T;
ll dist[MX][2],ways[MX][2],ans;
vpl adj[MX];

void gen(int ind) {
    FOR(i,1,N+1) dist[i][ind] = INF;
    priority_queue<pl,vpl,greater<pl>> pq;
    if (ind == 0) {
        dist[S][ind] = 0; pq.push({0,S});
    } else {
        dist[T][ind] = 0; pq.push({0,T});
    }
    while (sz(pq)) {
        auto a = pq.top(); pq.pop();
        if (dist[a.s][ind] < a.f) continue;
        for (auto b: adj[a.s]) if (dist[b.f][ind] > b.s+a.f) {
            dist[b.f][ind] = b.s+a.f;
            pq.push({dist[b.f][ind],b.f});
        }
    }
} 

vi al;

void genWays(int ind) {
    if (ind == 0) {
        ways[S][0] = 1;
    } else {
        ways[T][1] = 1;
        reverse(all(al));
    }
    
    for (int i: al) for (auto j: adj[i]) 
        if (j.s+dist[j.f][ind] == dist[i][ind]) 
            ways[i][ind] = ad(ways[i][ind],ways[j.f][ind]);
    
    if (ind == 1) {
        reverse(all(al));
    }
}

void genVert() {
    FOR(i,1,N+1) if (dist[i][0]+dist[i][1] == dist[T][0] && dist[i][0] == dist[i][1])
        ans = sub(ans,mul(mul(ways[i][0],ways[i][1]),mul(ways[i][0],ways[i][1])));
}

void genEdge() {
    FOR(i,1,N+1) for (auto a: adj[i]) 
        if (dist[i][0]+a.s+dist[a.f][1] == dist[T][0]) {
            if (dist[i][0] < a.s+dist[a.f][1] && dist[a.f][1] < a.s+dist[i][0]) 
                ans = sub(ans,mul(mul(ways[i][0],ways[a.f][1]),mul(ways[i][0],ways[a.f][1])));    
        }
}

int main() {
	// freopen("03.txt","r",stdin);
    cin >> N >> M >> S >> T;
    F0R(i,M) {
        int u,v,d; cin >> u >> v >> d;
        adj[u].pb({v,d}), adj[v].pb({u,d});
    }
    gen(0); gen(1);
    FOR(i,1,N+1) if (dist[i][0]+dist[i][1] == dist[T][0]) al.pb(i);
    sort(all(al),[](int a, int b) { return dist[a][0] < dist[b][0]; });
    
    // cout << sz(al) << "\n";
    genWays(0), genWays(1);
    // cout << ways[T][0] << " " << ways[S][1] << "\n";
    ans = mul(ways[T][0],ways[T][0]);
    genVert();
    genEdge();
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS
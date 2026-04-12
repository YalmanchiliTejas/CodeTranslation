#include <bits/stdc++.h>
 
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
 
#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=(int)(a)-1;i>=(int)(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)
 
#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
 
// #define DEBUG
 
#ifdef DEBUG
    #define dump(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dump(...)
#endif
 
template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}
 
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
 
const double EPS = 1e-10;
const double PI = acos(-1.0);
const ll inf =1LL << 62;
const ll mod=1000000007LL;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
 
ll extgcd(ll a,ll b,ll& x,ll& y){x=1,y=0;ll g=a;if(b!=0) g=extgcd(b,a%b,y,x),y-=a/b*x;return g;}
ll ADD(const ll &a, const ll &b,const ll &mod) { return (a+b)%mod;}
ll SUB(const ll &a, const ll &b,const ll &mod) { return (a-b+mod)%mod;}
ll MUL(const ll &a, const ll &b,const ll &mod) { return (1LL*a*b)%mod;}
ll DIV(const ll &a, const ll &b,const ll &mod) {ll x,y; extgcd(b,mod,x,y);return MUL(a,(x+mod)%mod,mod);}
 
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dice(1,6);
uniform_real_distribution<double> score(0.0,10.0);

int n;
int S, T;
using Edge = tuple<int, ll>;
vector<vector<Edge>> G;
vll min_cost; // S -> T

void dijkstra(){
    using Elem = tuple<ll, int>;
    priority_queue<Elem, vector<Elem>, greater<Elem>> q;
    q.push(Elem(0, S));
    min_cost = vll(n, inf);
    min_cost[S] = 0;

    while(q.size()){
        int v; ll d; tie(d, v) = q.top(); q.pop();
        if(v == T) break;
        if(d != min_cost[v]) continue;

        for(auto& e : G[v]){
            int nv; ll dd; tie(nv, dd) = e;
            ll nd = d + dd;
            if(chmin(min_cost[nv], nd)){
                q.push(Elem(nd, nv));
            }
        }
    }
}

vector<vi> Gs, Gr;
int N;
vi g2h;
const int M = 300000;
int newv[M];
int deg[M];
ll dpf[M];
ll dpb[M];

void dfs(int v){
    g2h[v] = N++;
    if(2 * min_cost[v] == min_cost[T]){
        newv[g2h[v]] = true;
    }
    for(auto& e : G[v]){
        int pv; ll dd; tie(pv, dd) = e;
        if(min_cost[pv] + dd == min_cost[v]){
            if(g2h[pv] == -1){
                dfs(pv);
            }
            if(2 * min_cost[pv] < min_cost[T] and min_cost[T] < 2 * min_cost[v]){
                int mv = N++;
                Gs[g2h[pv]].emplace_back(mv); deg[mv]++;
                Gs[mv].emplace_back(g2h[v]);  deg[g2h[v]]++;
                newv[mv] = true;
            }
            else {
                Gs[g2h[pv]].emplace_back(g2h[v]); deg[g2h[v]]++;
            }
        }
    }
}

void dfs2(vector<vi>& H, ll dp[], int v){
    ll cur = dp[v];
    for(auto& nv : H[v]){
        dp[nv] = ADD(dp[nv], cur, mod);
        if((--deg[nv]) == 0){
            dfs2(H, dp, nv);
        }
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m; cin >> n >> m;
    cin >> S >> T; S--, T--;

    G = vector<vector<Edge>>(n);
    rep(loop, m){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        G[a].emplace_back(Edge(b, c));
        G[b].emplace_back(Edge(a, c));
    }

    dijkstra();
    g2h = vi(n, -1);
    Gs = Gr = vector<vi>(M);
    dfs(T);
    dpf[g2h[S]] = 1;
    dfs2(Gs, dpf, g2h[S]);
    // rep(i, n){
    //     cerr << i+1 << " -> " << g2h[i] << endl;
    // }
    // cerr << "-----" << endl;
    // rep(i, N){
    //     cerr << dpf[i] << endl;
    // }
    rep(v, N) deg[v] = 0;
    rep(v, N){
        for(auto& nv : Gs[v]){
            Gr[nv].emplace_back(v); deg[v]++;
        }
    }
    dpb[g2h[T]] = 1;
    dfs2(Gr, dpb, g2h[T]);
    // cerr << "-----" << endl;
    // rep(i, N){
    //     cerr << dpb[i] << endl;
    // }
    assert(dpf[g2h[T]] == dpb[g2h[S]]);

    ll res = MUL(dpf[g2h[T]], dpf[g2h[T]], mod);
    rep(v, N){
        if(newv[v]){
            ll co = MUL(dpf[v], dpb[v], mod);
            res = SUB(res, MUL(co, co, mod), mod);
        }
    }
    cout << res << endl;

    return 0;
}

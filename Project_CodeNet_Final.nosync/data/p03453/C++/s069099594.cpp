#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

template<typename T> class Dijkstra {
public:
	struct edge{
		int to; T cost;
	};
	vector<vector<edge> > G;
	vector<T> d;
	int V;
	using pti = pair<T,int>;
	Dijkstra(int node_size){
		V = node_size;
		G.resize(V),d.resize(V,numeric_limits<T>::max());
	}
	//無向グラフの場合
	void add_edge(int u,int v,T cost){
		G[u].pb((edge){v,cost}),G[v].pb((edge){u,cost});
	}
	void solve(int s){
		priority_queue<pti,vector<pti>,greater<pti> > que;
		d[s] = 0;
		que.push(pti(0,s));
		while(!que.empty()){
			pti p = que.top();
			que.pop();
			int v = p.second;
			if(d[v] < p.first) continue;
			for(auto& w : G[v]){
				if(d[w.to] > d[v] + w.cost){
					d[w.to] = d[v] + w.cost;
					que.push(pti(d[w.to],w.to));
				}
			}
		}
	}
};

ll mod_pow(ll a,ll b)
{
    a %= MOD;
    ll res = 1;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll add(ll x,ll y)
{
    return (x + y)%MOD;
}

ll sub(ll x,ll y)
{
    return (x+MOD-y)%MOD;
}

ll mul(ll x,ll y)
{
    return x*y%MOD;
}

struct tri
{
    int x,y,z;
};

ll dp1[MAX_N],dp2[MAX_N];

void solve(int u,ll* dp,vl& d,vvi& graph)
{
    dp[u] = 1;
    set<pll> st;
    st.insert(pll(0,u));
    while(len(st)){
        pll p = *st.begin();
        st.erase(st.begin());
        for(int v : graph[p.se]){
            dp[v] = add(dp[v],dp[p.se]);
            st.insert(pll(d[v],v));
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int s,t;
    cin >> s >> t;
    --s,--t;
    Dijkstra<ll> d1(n),d2(n);
    vector<tri> ed(m);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        d1.add_edge(a-1,b-1,c);
        d2.add_edge(a-1,b-1,c);
        ed[i] = (tri){a-1,b-1,c};
    }
    d1.solve(s),d2.solve(t);
    ll opt = d1.d[t];
    vvi graph1(n),graph2(n);
    vector<tri> hoge;
    rep(i,m){
        tri p = ed[i];
        if(d1.d[p.x] > d1.d[p.y]){
            if(d1.d[p.y]+d2.d[p.x]+p.z == opt){
                hoge.pb((tri){p.y,p.x,p.z});
                graph1[p.y].pb(p.x);
                graph2[p.x].pb(p.y);
            }
        }else{
            if(d1.d[p.x]+d2.d[p.y]+p.z == opt){
                hoge.pb(p);
                graph1[p.x].pb(p.y);
                graph2[p.y].pb(p.x);
            }
        }
    }
    solve(s,dp1,d1.d,graph1);
    solve(t,dp2,d2.d,graph2);
    ll ans = mod_pow(dp1[t],2);
    ll sb = 0;
    if(opt % 2 == 0){
        rep(i,len(hoge)){
            tri p = hoge[i];
            if(d1.d[p.x] < opt/2 && d1.d[p.y] > opt/2){
                sb = add(sb,mod_pow(mul(dp1[p.x],dp2[p.y]),2));
            }
        }
        rep(i,n){
            if(d1.d[i] == opt/2){
                sb = add(sb,mod_pow(mul(dp1[i],dp2[i]),2));
            }
        }
    }else{
        rep(i,len(hoge)){
            tri p = hoge[i];
            if(d1.d[p.x] <= opt/2 && d1.d[p.y] > opt/2){
                sb = add(sb,mod_pow(mul(dp1[p.x],dp2[p.y]),2));
            }
        }
    }
    cout << sub(ans,sb) << "\n";
    return 0;
}

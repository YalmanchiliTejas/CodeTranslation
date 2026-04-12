#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
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
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

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

template<typename T> class Dinic {
private:
    struct edge{
        int to;
        T cap;
        int rev;
    };
    int V;
    T cap_sum;
    vector<vector<edge> > G;
    vector<int> level,iter;
    //辺を張る
    void add_edge(int from,int to,T cap)
    {
    	G[from].push_back((edge){to,cap,(int)G[to].size()});
    	G[to].push_back((edge){from,(T)0,(int)G[from].size()-1});
    }
    void bfs(int s)
    {
    	fill(level.begin(),level.end(),-1);
    	queue<int> que;
    	level[s] = 0;
    	que.push(s);
    	while(!que.empty()){
    		int v = que.front();
    		que.pop();
    		rep(i,G[v].size()){
    			edge &e = G[v][i];
    			if(e.cap > 0 && level[e.to] < 0){
    				level[e.to] = level[v] + 1;
    				que.push(e.to);
    			}
    		}
    	}
    }
    T dfs(int v,int t,T f)
    {
    	if(v==t){
    		return f;
    	}
    	for(int &i = iter[v];i<(int)G[v].size();i++){
    		edge &e = G[v][i];
    		if(e.cap > 0 && level[v] < level[e.to]){
    			T d = dfs(e.to,t,min(f,e.cap));
    			if(d>0){
    				e.cap -= d;
    				G[e.to][e.rev].cap += d;
    				return d;
    			}
    		}
    	}
    	return 0;
    }
    T solve(){
        T flow = 0;
    	for(;;){
    		bfs(V);
    		if(level[V+1]<0){
    			return flow;
    		}
    		fill(iter.begin(),iter.end(),0);
    		T f;
    		while((f=dfs(V,V+1,numeric_limits<T>::max())) > 0){
    			flow += f;
    		}
    	}
    }
public:
    Dinic(int node_size){
        V = node_size, cap_sum = 0;
        G.resize(V+2),level.resize(V+2),iter.resize(V+2);
    }
    void add_edge(int from,int to,T min_cap,T max_cap)
    {
        cap_sum += min_cap;
        add_edge(from,to,max_cap-min_cap);
        if(min_cap){
            add_edge(V,to,min_cap);
            add_edge(from,V+1,min_cap);
        }
    }
    bool check(int s, int t){
        add_edge(t,s,numeric_limits<T>::max());
        T res = solve();
        return (res >= cap_sum);
    }
    //最大流を計算
    T max_flow(int s,int t)
    {
        add_edge(V,s,numeric_limits<T>::max());
        add_edge(t,V+1,numeric_limits<T>::max());
        return solve() - cap_sum;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        vp vec(m);
        rep(i,m){
            cin >> vec[i].fi >> vec[i].se;
        }
        int ans = m+1;
        int l=-1,r=-1;
        int max_cap = m;
        rrep(i,m/n+1){
            while(max_cap >= i){
                Dinic<int> dn(m+n+2);
                rep(j,m){
                    dn.add_edge(0,j+1,1,1);
                }
                rep(j,m){
                    dn.add_edge(j+1,m+vec[j].fi,0,1);
                    dn.add_edge(j+1,m+vec[j].se,0,1);
                }
                rep(k,n){
                    dn.add_edge(m+k+1,m+n+1,i,max_cap);
                }
                if(dn.check(0,m+n+1)){
                    if(ans >= max_cap - i){
                        ans = max_cap - i;
                        l = i, r = max_cap;
                    }
                    max_cap--;
                }else{
                    break;
                }
            }
        }
        cout << l << " " << r << "\n";
    }
    return 0;
}


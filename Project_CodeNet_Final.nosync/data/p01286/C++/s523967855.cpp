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
#define sar(a,n) cout<<#a<<":";rep(kbrni,n)cout<<" "<<a[kbrni];cout<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define svecp(v) cout<<#v<<":";each(kbrni,v)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl
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

//最大流量がint,頂点数がMAX_N
//Dinic<int> dn(MAX_N);
//適宜add_edge,max_flowを用いる
template<typename T> class Dinic {
public:
    struct edge{
        int to;
        T cap;
        int rev;
    };
    vector<vector<edge> > G;
    vector<int> level,iter;
    int n;
    Dinic(int node_size){
        n = node_size;
        G.resize(node_size),level.resize(node_size),iter.resize(node_size);
    }
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
    //最大流を計算
    T max_flow(int s,int t)
    {
    	T flow = 0;
    	for(;;){
    		bfs(s);
    		if(level[t]<0){
    			return flow;
    		}
    		fill(iter.begin(),iter.end(),0);
    		T f;
    		while((f=dfs(s,t,numeric_limits<T>::max())) > 0){
    			flow += f;
    		}
    	}
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        int h,w,c,m,nw,nc,nm;
        cin >> h >> w >> c >> m >> nw >> nc >> nm;
        if(h == -1){
            break;
        }
        int al = h+2*w+2*c+m;
        Dinic<int> d(al+7);
        rep(i,h){
            d.add_edge(al,i,1);
        }
        rep(i,w){
            int n;
            cin >> n;
            rep(j,n){
                int ag;
                cin >> ag;
                --ag;
                d.add_edge(ag,i+h,1);
            }
            d.add_edge(h+i,h+w+i,1);
        }
        rep(i,c){
            int n;
            cin >> n;
            rep(j,n){
                int ag;
                cin >> ag;
                --ag;
                d.add_edge(h+w+ag,h+2*w+i,1);
            }
            d.add_edge(h+2*w+i,h+2*w+c+i,1);
        }
        rep(i,m){
            int n;
            cin >> n;
            rep(j,n){
                int ag;
                cin >> ag;
                --ag;
                d.add_edge(ag+h+2*w+c,h+2*w+2*c+i,1);
            }
            d.add_edge(h+2*w+2*c+i,al+1,1);
        }
        rep(i,h){
            d.add_edge(i,al+2,1);
        }
        d.add_edge(al+2,al+3,nw);
        rep(i,c){
            d.add_edge(al+3,h+2*w+i,1);
        }
        rep(i,w){
            d.add_edge(h+w+i,al+4,1);
        }
        d.add_edge(al+4,al+5,nc);
        rep(i,m){
            d.add_edge(al+5,h+2*w+2*c+i,1);
        }
        rep(i,c){
            d.add_edge(h+2*w+c+i,al+6,1);
        }
        d.add_edge(al+6,al+1,nm);
        cout << d.max_flow(al,al+1) << "\n";
    }
    return 0;
}


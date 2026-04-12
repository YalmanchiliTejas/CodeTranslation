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

const int inf = 1 << 29;

class Dinic{
	public :
		void init(int _n){
			n=_n;
			G.resize(n);
			iter.resize(n);
			level.resize(n);
		}

		void add_edge(int from,int to ,int cap){
			G[from].push_back((edge){to,cap,(int)G[to].size()});
			G[to].push_back((edge){from,0,(int)G[from].size()-1});
		}
	
		void add_edge_both(int from,int to ,int cap){
			add_edge(from,to,cap);
			add_edge(to,from,cap);
		}
	
		int max_flow(int s,int t){
			int flow=0;
			for(;;){
				bfs(s);
				if(level[t]<0) return flow;
				iter.assign(n,0);
				int f;
				while((f=dfs(s,t,DINIC_INF))>0){
					flow+=f;
				}
			}
		}
	private:
	
		int n;
		struct edge{int to,cap,rev;};
		static const int DINIC_INF = inf;
		vector< vector<edge> > G;
		vi level;
		vi iter;
	
		void bfs(int s){
			level.assign(n,-1);
			queue<int> que;
			level[s]=0;
			que.push(s);
			while(!que.empty()){
				int v=que.front();que.pop();
				for(int i=0;i< (int)G[v].size(); i++){
					edge &e=G[v][i];
					if(e.cap>0 && level[e.to] <0){
						level[e.to]=level[v]+1;
						que.push(e.to);
					}
				}
			}
		}

		int dfs(int v,int t,int f){
			if(v==t) return f;
			for(int &i=iter[v];i<(int)G[v].size();i++){
				edge &e= G[v][i];
				if(e.cap>0 && level[v]<level[e.to]){
					int d=dfs(e.to,t,min(f,e.cap));
					if(d>0){
						e.cap -=d;
						G[e.to][e.rev].cap+=d;
						return d;
					}
				}
			}
			return 0;
		}	
};

const int N = 51;
int wh[N][N];
int cw[N][N];
int mc[N][N];

int main(void){
    for(int H, W, C, M, nw, nc, nm; cin >> H >> W >> C >> M >> nw >> nc >> nm, H != -1;){
        int s = 0, t = 1;
        int h1 = 2         , h2 = h1 + H;
        int w1 = h2 + H    , w2 = w1 + W + 1;
        int c1 = w2 + W + 1, c2 = c1 + C + 1;
        int m1 = c2 + C + 1, m2 = m1 + M + 1;
        int n  = m2 + M + 1;

        rep(i, W) rep(j, H) wh[i][j] = 0;
        rep(i, C) rep(j, W) cw[i][j] = 0;
        rep(i, M) rep(j, C) mc[i][j] = 0;
        rep(i, W){
            int m; cin >> m;
            rep(loop, m){
                int idx; cin >> idx; idx--;
                wh[i][idx] = 1;
            }
        }
        rep(i, C){
            int m; cin >> m;
            rep(loop, m){
                int idx; cin >> idx; idx--;
                cw[i][idx] = 1;
            }
        }
        rep(i, M){
            int m; cin >> m;
            rep(loop, m){
                int idx; cin >> idx; idx--;
                mc[i][idx] = 1;
            }
        }

        Dinic dinic; dinic.init(n);

        rep(h, H){
            dinic.add_edge(s, h1 + h, 1);
            dinic.add_edge(h1 + h, h2 + h, 1);
        }

        rep(h, H){
            rep(w, W + 1){
                if(w < W and not wh[w][h]) continue;
                dinic.add_edge(h2 + h, w1 + w, 1);
            }
        }
        rep(w, W){
            dinic.add_edge(w1 + w, w2 + w, 1);
        }
        dinic.add_edge(w1 + W, w2 + W, nw);

        rep(w, W + 1){
            rep(c, C + 1){
                if(w == W and c == C) continue;
                if(w < W and c < C and not cw[c][w]) continue;
                dinic.add_edge(w2 + w, c1 + c, 1);
            }
        }
        rep(c, C){
            dinic.add_edge(c1 + c, c2 + c, 1);
        }
        dinic.add_edge(c1 + C, c2 + C, nc);

        rep(c, C + 1){
            rep(m, M + 1){
                if(c == C and m == M) continue;
                if(c < C and m < M and not mc[m][c]) continue;
                dinic.add_edge(c2 + c, m1 + m, 1);
            }
        }
        rep(m, M){
            dinic.add_edge(m1 + m, m2 + m, 1);
            dinic.add_edge(m2 + m, t, 1);
        }
        dinic.add_edge(m1 + M, m2 + M, nm);
        dinic.add_edge(m2 + M, t, nm);

        cout << dinic.max_flow(0, 1) << endl;
    }

    return 0;
}
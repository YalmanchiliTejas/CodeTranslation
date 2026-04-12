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

template<typename T> class PushRelabel{
private:
    struct edge{
        int to,rev;
        T f,cap;
    };
    vector<vector<edge> > G;
    int V;
public:
    PushRelabel(int node_size){
        V = node_size;
        G.resize(V);
    }
    void add_edge(int from,int to,T capacity){
        G[from].push_back((edge){to,(int)G[to].size(),(T)0,capacity});
        G[to].push_back((edge){from,(int)G[from].size()-1,(T)0,(T)0});
    }
    T solve(int s,int t){
        vector<int> d(V,0),mxd(V,0);
        vector<T> ex(V,0);
        d[s] = V-1;
        for(edge& e : G[s]){
            e.f = e.cap;
            G[e.to][e.rev].f = -e.cap;
            ex[e.to] += e.cap;
        }
        for(int sz = 0;;){
            if(sz == 0){
                rep(i,V){
                    if(i != s && i != t && ex[i] > 0){
                        if(sz != 0 && d[i] > d[mxd[0]]){
                            sz = 0;
                        }
                        mxd[sz++] = i;
                    }
                }
            }
            if(sz == 0) break;
            while(sz){
                int i = mxd[sz-1];
                bool push = false;
                for(int j = 0; j < (int)G[i].size() && ex[i] != 0; j++){
                    edge& e = G[i][j];
                    if(d[i] == d[e.to] + 1 && e.cap - e.f > 0){
                        //push操作
                        push = true;
                        T df = min(e.cap - e.f, ex[i]);
                        e.f += df, G[e.to][e.rev].f -= df;
                        ex[i] -= df, ex[e.to] += df;
                        if(ex[i] == 0){
                            sz--;
                        }
                    }
                }
                if(!push){
                    //relabel操作
                    d[i] = numeric_limits<int>::max();
                    for(edge& e : G[i]){
                        if(d[i] > d[e.to] + 1 && e.cap - e.f > 0){
                            d[i] = d[e.to] + 1;
                        }
                    }
                    if(d[i] > d[mxd[0]]){
                        sz = 0;
                        break;
                    }
                }
            }
        }
        T flow = 0;
        for(edge& e : G[s]){
            flow += e.f;
        }
        return flow;
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
        PushRelabel<int> d(al+7);
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
        cout << d.solve(al,al+1) << "\n";
    }
    return 0;
}


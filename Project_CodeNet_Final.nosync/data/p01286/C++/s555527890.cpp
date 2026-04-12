#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif

typedef pair<int,int> pii;
const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

//O(F|E|).F:=maxflow
struct max_flow{
    struct edge{int to,cap,rev;};
    vector<vector<edge>> graph;
    vector<bool> done;
    max_flow(int size):graph(size),done(size){}
    void add_edge(int from,int to,int cap){
        graph[from].push_back(edge{to,cap,(int)graph[to].size()});
        graph[to].push_back(edge{from,0,(int)graph[from].size()-1});
    }
    int dfs(int v,int t,int f){
        if(v==t) return f;
        done[v]=true;
        for(auto &e:graph[v]){
            if(done[e.to] or e.cap<=0) continue;
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                graph[e.to][e.rev].cap+=d;
                return d;
            }
        }
        return 0;
    }
    int calc_max_flow(int s,int t){
        int flow=0;
        while(true){
            fill(done.begin(),done.end(),false);
            int f=dfs(s,t,inf);
            if(f==0) return flow;
            flow+=f;
        }
    }
};

void solve(int h,int w,int c,int m,int n_w,int n_c,int n_m){
    max_flow mf(6001);
    int s=0,t=6000,v[6]={5995,5996,5997,5998,5999,5000};
    vector<int> h_range[2],w_range[2],c_range[2],m_range[2];
    rep(i,1,1+h){
        h_range[0].push_back(i);
        h_range[1].push_back(i+2000);
        mf.add_edge(i,i+2000,1);
    }
    rep(i,301,301+w){
        w_range[0].push_back(i);
        w_range[1].push_back(i+2000);
        mf.add_edge(i,i+2000,1);
    }
    rep(i,601,601+c){
        c_range[0].push_back(i);
        c_range[1].push_back(i+2000);
        mf.add_edge(i,i+2000,1);
    }
    rep(i,901,901+m){
        m_range[0].push_back(i);
        m_range[1].push_back(i+2000);
        mf.add_edge(i,i+2000,1);
    }
    for(int i:h_range[0]) mf.add_edge(s,i,1);
    for(int i:h_range[1]) mf.add_edge(i,v[0],1);
    for(int i:w_range[1]) mf.add_edge(i,v[2],1);
    for(int i:c_range[0]) mf.add_edge(v[1],i,1);
    for(int i:c_range[1]) mf.add_edge(i,v[4],1);
    for(int i:m_range[0]) mf.add_edge(v[3],i,1);
    for(int i:m_range[1]) mf.add_edge(i,t,1);
    mf.add_edge(v[0],v[1],n_w);
    mf.add_edge(v[2],v[3],n_c);
    mf.add_edge(v[4],v[5],n_m);
    mf.add_edge(v[5],t,n_m);
    rep(i,301,301+w){
        int n;
        cin >> n;
        rep(j,0,n){
            int x;
            cin >> x;
            mf.add_edge(x+2000,i,1);
        }
    }
    rep(i,601,601+c){
        int n;
        cin >> n;
        rep(j,0,n){
            int x;
            cin >> x;
            mf.add_edge(300+x+2000,i,1);
        }
    }
    rep(i,901,901+m){
        int n;
        cin >> n;
        rep(j,0,n){
            int x;
            cin >> x;
            mf.add_edge(600+x+2000,i,1);
        }
    }
    cout << mf.calc_max_flow(s,t) << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    for(;;){
        int h,w,c,m,n_w,n_c,n_m;
        cin >> h >> w >> c >> m >> n_w >> n_c >> n_m;
        if(h<0 and w<0 and c<0 and m<0 and n_w<0 and n_c<0 and n_m<0) break;
        solve(h,w,c,m,n_w,n_c,n_m);
    }
    return 0;
}
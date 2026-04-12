#include <bits/stdc++.h>
using namespace std;
using i64=int_fast64_t;
using pii=pair<int,int>;
template <class T> constexpr T inf=numeric_limits<T>::max() / (T)2;
template <class T> using minheap=priority_queue<T,vector<T>,greater<T>>;
#define fir first
#define sec second
#define mkp make_pair
#define mkt make_tuple
#define emb emplace_back
#define all(v) begin(v),end(v)




struct edge {
    int to;
    int cap;
    int rev;
    edge(int a,int b,int c) : to(a),cap(b),rev(c) {}
};

bool vis[668];
vector<edge> grh[668];

void addedge(int s,int t,int cp) {
    int ss=grh[s].size();
    int tt=grh[t].size();
    grh[s].emb(t,cp,tt);
    grh[t].emb(s,0,ss);
}

bool dfs(int x,int t) {
    vis[x]=true;
    if(x==t) return true; 
    int i=-1;
    for(auto &e:grh[x]) {
        ++i;
        if(vis[e.to] || e.cap<=0) continue;
        if(dfs(e.to,t)) {
            e.cap--;
            grh[e.to][e.rev].cap++;
            return true;
        }
    }
    return false;
}

int maxflow(int s,int t) {
    int ret=0;
    while(memset(vis,0,sizeof(vis)), dfs(s,t)) {
        ret++;
    }
    return ret;
}

int H,W,C,M,nw,nc,nm;

void solve() {
    memset(grh,0,sizeof(grh));

    const int s=300;
    const int t=301;
    const int wnone1=302,wnone2=303,cnone1=304,cnone2=305,mnone=306;

    addedge(wnone1,wnone2,nw);
    addedge(cnone1,cnone2,nc);
    addedge(mnone,t,nm);

    for(int i=0; i<H; ++i) {
        addedge(s,i,1);
        addedge(i,wnone1,1);
    }

    for(int i=0,k; i<W; ++i) {
        cin>>k;
        for(int j=0,h; j<k; ++j) {
            cin>>h;
            h--;
            addedge(h,i+H,1);
        }
        addedge(i+H,i+H+334,1);
        addedge(i+H+334,cnone1,1);
    }

    for(int i=0,k; i<C; ++i) {
        cin>>k;
        for(int j=0,w; j<k; ++j) {
            cin>>w;
            w--;
            addedge(w+H+334,i+H+W,1);
        }
        addedge(wnone2,H+W+i,1);
        addedge(i+W+H,i+H+W+334,1);
        addedge(H+W+i+334,mnone,1);
    }

    for(int i=0,k; i<M; ++i) {
        cin>>k;
        for(int j=0,c; j<k; ++j) {
            cin>>c;
            c--;
            addedge(c+H+W+334,i+H+W+C,1);
        }
        addedge(cnone2,i+H+W+C,1);
        addedge(i+H+W+C,i+H+W+C+334,1);
        addedge(i+H+W+C+334,t,1);
    }
    
    cout<<maxflow(s,t)<<endl;
}


signed main() {
    #ifdef LOCAL
        freopen("stdin.txt","rt",stdin);
    #endif

    while(cin>>H>>W>>C>>M>>nw>>nc>>nm) {
        if(max({H,W,C,M,nw,nc,nm})<0) break;
        solve();
    }
}

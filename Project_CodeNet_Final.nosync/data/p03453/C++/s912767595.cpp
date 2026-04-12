#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define FORE(x,c) for(auto &x:c)
#define REPF(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define REP(i,n) REPF(i,0,n)
#define REPR(i,n) for(int i=(int)(n);i>=0;--i)
#define SZ(c) ((int)c.size())
#define CONTAIN(c,x) (c.find(x)!=end(c))
#define OUTOFRANGE(y,x,h,w) (y<0||x<0||y>=h||x>=w)
#define dump(...)
const signed INF_=1001001001; const ll INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct{template<class T> operator T(){T x;cin>>x;return x;}} IN;
struct before_main_function {
    before_main_function() {
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
        #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

const int MOD=1e9+7;
signed main() {
    int N,M,S,T;
    cin>>N>>M>>S>>T;
    S--,T--;
    vector<vector<pii>> g(N);
    vector<vector<int>> edge(M);
    REP(i,M) {
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].push_back({v,d});
        g[v].push_back({u,d});
        edge[i]={u,v,d};
    }
    vector<int> dist(N,INF);
    heap<pii> hp;
    hp.push({0,S});
    dist[S]=0;
    while(!hp.empty()) {
        int v=hp.top().second; hp.pop();
        FORE(e,g[v]) {
            int w=e.first;
            int c=e.second;
            if(chmin(dist[w],dist[v]+c)) {
                hp.push({dist[w],w});
            }
        }
    }
    
    vector<int> dp1(N,0),dp2(N,0);
    vector<int> ch(N,0);
    vector<pii> tmp(N);
    REP(i,N) tmp[i]={dist[i],i};
    sort(ALL(tmp));
    dp1[S]=1;
    REP(i,N) {
        int v=tmp[i].second;
        ch[v]=1;
        FORE(e,g[v]) {
            if(ch[e.first]) continue;
            if(dist[v]+e.second==dist[e.first]) {
                (dp1[e.first]+=dp1[v])%=MOD;
            }
        }
    }
    ch=vector<int>(N,0);
    sort(RALL(tmp));
    dp2[T]=1;
    REP(i,N) {
        int v=tmp[i].second;
        ch[v]=1;
        FORE(e,g[v]) {
            if(ch[e.first]) continue;
            if(dist[v]-e.second==dist[e.first]) {
                (dp2[e.first]+=dp2[v])%=MOD;
            }
        }
    }
    int ans=dp1[T]*dp1[T]%MOD;
    int neg=0;
    REP(i,N) {
        if(2*dist[i]==dist[T]) {
            neg+=dp1[i]*dp1[i]%MOD*dp2[i]%MOD*dp2[i]%MOD;
            neg%=MOD;
        }
    }
    REP(i,M) {
        int u=edge[i][0],v=edge[i][1],c=edge[i][2];
        if(2*dist[u]<dist[T] && 2*dist[v]>dist[T] && dist[u]+c==dist[v]) {
            neg+=dp1[u]*dp1[u]%MOD*dp2[v]%MOD*dp2[v]%MOD;
            neg%=MOD;
        }
        if(2*dist[v]<dist[T] && 2*dist[u]>dist[T] && dist[v]+c==dist[u]) {
            neg+=dp1[v]*dp1[v]%MOD*dp2[u]%MOD*dp2[u]%MOD;
            neg%=MOD;
        }
    }
    ans=(ans-neg+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}

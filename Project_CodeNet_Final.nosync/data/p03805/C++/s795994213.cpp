#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,n) for(int i=1,i##_len=(n); i<=i##_len; ++i)
#define drep(i,n) for(int i=(n)-1; i>=0; --i)
#define srep(i,s,t) for(int i=(s);i<(t);++i)
#define rng(obj) (obj).begin(), (obj).end()
#define maxs(x,y) (x=max((x),(y)))
#define mins(x,y) (x=min((x),(y)))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x=max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T>>
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vp = vector<P>;
inline int in() { int x; cin>>x; return x;}
template <class T> inline istream& operator>>(istream&i,v(T)&v)
{ rep(j,sz(v))i>>v[j];return i;}
template <class T> string join(const v(T)&v)
{ stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template <class T> inline ostream& operator<<(ostream&o,const v(T)&v)
{ if(sz(v))o<<join(v); return o;}
template <class T1,class T2> inline istream& operator>>(istream&i ,pair<T1,T2>&v)
{ return i>>v.fi>>v.se;}
template <class T1,class T2> inline ostream& operator<<(ostream&o ,pair<T1,T2>&v)
{ return o<<v.fi<<","<<v.se;}
template <class T> inline ll suma(const v(T)& a) 
{ ll res(0); for(auto&& x:a) res += x; return res;}
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const double eps = 1e-10;
#define dame {puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;
#define fileio ifstream fio; if(argc>=2){fio.open(argv[1]); std::cin.rdbuf(fio.rdbuf());}
//----------------------------------------------------------------
bool graph[8][8];
int dfs(int v,int n,v(bool) visited){
    bool all_visited=true;
    rep(i,n) if(visited[i]==false) all_visited = false;
    if(all_visited) return 1;
    int ret = 0;
    rep(i,n){
        if(graph[v][i]==false) continue;
        if(visited[i]) continue;
        visited[i] = true;
        ret += dfs(i,n,visited);
        visited[i] = false;
    }
    return ret;
}
int main(int argc,char* argv[]){
    fileio
    int n = in();
    int m = in();
    rep(i,m){
        int s = in(),t = in(); s--;t--;
        graph[s][t] = true;
        graph[t][s] = true;
    }
    v(bool) visited(n,false);
    visited[0]=true;
    cout<<dfs(0,n,visited);
}
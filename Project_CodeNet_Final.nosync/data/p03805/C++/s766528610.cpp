#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll=long long;
using vi=vector<int>;
using vl=vector<long long>;
using pii=pair<int,int>;
using pll=pair<long long,long long>;
#define ITR(i,c) for(auto i=begin(c);i!=end(c);++i)
#define FORE(x,c) for(auto &x:c)
#define FOR(i,a,n) for(int i=a,i##_len=(int)(n);i<i##_len;++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i=(int)n;i>=0;--i)
#define ALL(c) begin(c),end(c)
#define RALL(c) rbegin(c),rend(c)   // c++14
#define SZ(c) ((int)c.size())
#define EXIST(c,x) (c.find(x)!=end(c))
#define dump(...)
const int DX[9]={0,1,0,-1,1,1,-1,-1,0}, DY[9]={-1,0,1,0,-1,1,1,-1,0};
const int INF=1001001001; const long long INFLL=1001001001001001001ll;
template<class T> ostream& operator << (ostream &os, const vector<T> &v) {
    ITR(i,v) os << *i << (i==end(v)-1 ? "" : " "); return os; }
template<class T> istream& operator >> (istream &is, vector<T> &v) {
    ITR(i,v) is >> * i; return is; }
template<class T> istream& operator >> (istream &is, pair<T,T> &p) {
        is >> p.first >> p.second; return is; }
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
//------------------------------------------------------------------------------
struct before_main_function {
    before_main_function() {
    #ifdef int
        cerr<<"\x1b[7m"<<"'int' is defined as 'long long' !!!!"<<"\x1b[m"<<endl;
    #endif
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
    }
} before_main_function;
//------------------------------------------------------------------------------

vector<vector<int>> g;
vector<bool> r;
int N,M;
int dfs(int v) {
    bool f=false;
    REP(i,N) {
        if(!r[i]) {
            f=true;
            break;
        }
    }
    if(!f) {
        return 1;
    }

    int ret=0;
    FORE(u,g[v]) {
        if(r[u]) continue;
        r[u]=true;
        ret+=dfs(u);
        r[u]=false;
        f=true;
    }
    return ret;
}
signed main() {
    cin>>N>>M;
    r=vector<bool>(N,false);
    g=vector<vector<int>>(N);
    REP(i,M) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    r[0]=true;
    cout<<dfs(0)<<endl;
    return 0;
}

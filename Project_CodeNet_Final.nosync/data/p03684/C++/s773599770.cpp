#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
#define INF (1001001001)
#define INFLL (1001001001001001001ll)
template<class T> ostream& operator << (ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v)) os<<*i<<(i==end(v)-1?"":" "); return os; }
template<class T> istream& operator >> (istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i; return is; }
template<class T> istream& operator >> (istream &is, pair<T,T> &p) {
    is>>p.first>>p.second; return is; }
template <class T> bool chmax(T &a,const T &b) {if(a<b) {a=b;return 1;} return 0;}
template <class T> bool chmin(T &a,const T &b) {if(b<a) {a=b;return 1;} return 0;}
template <class T> using heap = priority_queue<T,vector<T>,greater<T>>;
struct before_main_function {
    before_main_function() {
        #ifdef int
            #undef INF
            #define INF INFLL
            #define stoi stoll
        #endif
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
        #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

struct union_find {
    vector<int> data;
    union_find(int size) : data(size, -1) { }
    void unite(int x, int y) {
        x = root(x); y = root(y);
        if(x != y) {
            if(data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};
signed main() {
    int n;
    cin>>n;
    vector<pii> x(n),y(n);
    REP(i,n) {
        cin>>x[i].first;
        cin>>y[i].first;
        x[i].second=y[i].second=i;
    }
    sort(ALL(x));
    sort(ALL(y));
    vector<vector<int>> edge;
    REP(i,n-1) {
        int ax=x[i].second;
        int bx=x[i+1].second;
        int cx=abs(x[i].first-x[i+1].first);
        edge.push_back({cx,ax,bx});
        int ay=y[i].second;
        int by=y[i+1].second;
        int cy=abs(y[i].first-y[i+1].first);
        edge.push_back({cy,ay,by});
    }
    union_find uf(n);
    sort(ALL(edge));
    int ans=0;
    REP(i,SZ(edge)) {
        int c=edge[i][0];
        int a=edge[i][1];
        int b=edge[i][2];
        if(uf.same(a,b)) continue;
        uf.unite(a,b);
        ans+=c;
    }
    cout<<ans<<endl;
    return 0;
}

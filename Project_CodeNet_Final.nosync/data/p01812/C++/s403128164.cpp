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
#define OUTOFRANGE(y,x,h,w) ((y)<0||(x)<0||(y)>=(h)||(x)>=(w))
#define dump(...)
const signed INF_=1001001001; const long long INF=1001001001001001001LL;
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
        #define endl "\n"
        cin.tie(0);ios::sync_with_stdio(false);
        cout<<setprecision(15)<<fixed;
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> d(M);
    vector<int> id(N, -1);
    cin >> d;
    REP(i, M) id[d[i] - 1] = i;
    int mask = (1 << M) - 1;
    vector<vector<int>> g(N, vector<int>(K));
    cin >> g;
    vector<int> dist(1 << M, INF);
    dist[mask] = 0;
    queue<int> q;
    q.push(mask);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        REP(i, K) {
            int w = 0;
            REP(j, M) {
                if (v >> j & 1) {
                    int idx = id[g[d[j] - 1][i] - 1];
                    if (idx == -1) continue;
                    w or_eq 1 << idx;
                }
            }
            if (chmin(dist[w], dist[v] + 1)) {
                q.push(w);
            }
        }
    }
    cout << dist[0] << endl;
    return 0;
}



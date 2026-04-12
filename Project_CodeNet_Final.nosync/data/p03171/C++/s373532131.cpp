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
#define FORE(x,c) for(auto &&x:c)
#define REPF(i,a,n) for(int i=a,i##len=(int)(n);i<i##len;++i)
#define REP(i,n) REPF(i,0,n)
#define REPR(i,n) for(int i=(int)(n);i>=0;--i)
#define SZ(c) ((int)c.size())
#define CONTAIN(c,x) (c.find(x)!=end(c))
#define INSEG(l,x,r) ((l)<=(x)&&(x)<(r))
#define dump(...)
#define pb push_back
#define _ 0
const signed INF_=1001001001; const long long INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T, class U> bool chmax(T &a,const U &b){return a<b?a=b,1:0;}
template<class T, class U> bool chmin(T &a,const U &b){return a>b?a=b,1:0;}
template <class T> void PSUM(T& c) {partial_sum(begin(c), end(c), begin(c));}
template<class T> using heap=priority_queue<T,vector<T>,greater<T>>;
struct before_main_function {
    before_main_function() {
        cin.tie(0); ios::sync_with_stdio(false);
        cout << setprecision(15) << fixed;
        #define endl "\n"
    }
} before_main_function;
//------------------8<------------------------------------8<--------------------

int N;
vector<int> a;
int dp[3000][3000][2];
int rec(int l, int r, int p) {
    if (l == r) {
        if (p == 0) return 0;
        else return a[l];
    }

    auto &DP = dp[l][r][p];
    if (DP != -1) return DP;

    int ret;
    int y1 = rec(l + 1, r, p ^ 1);
    int y2 = rec(l, r - 1, p ^ 1);
    if (p == 0) {
        // taro
        ret = min(y1, y2);
    } else {
        // jiro
        ret = max(y1 + a[l], y2 + a[r]);
    }
    return DP = ret;
}
signed main() {
    REP(i, 3000) REP(j, 3000) REP(k, 2) dp[i][j][k] = -1;
    cin >> N;
    a.resize(N);
    cin >> a;
    int S = accumulate(ALL(a), 0LL);

    cout << (S - rec(0, N - 1, 0) * 2) << endl;
    return (0^_^0);
}


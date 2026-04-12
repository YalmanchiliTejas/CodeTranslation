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

int N, M;
const int MAX_N = 4001;
int dp[MAX_N][MAX_N];
int fact[MAX_N];
int fact_inv[MAX_N];
int bin_pow_mod(int a, int b, int m = M) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) ret = (ret * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ret;
}
int combination(int n, int r) {
    return fact[n] * fact_inv[n - r] % M * fact_inv[r] % M;
}
void init_fact() {
    fact[0] = 1, fact_inv[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        fact[i] = fact[i - 1] * i % M;
        fact_inv[i] = bin_pow_mod(fact[i], M - 2);
    }
}
void calc_dp() {
    dp[0][0] = 1;
    REPF(i, 1, N + 1) {
        dp[i][0] = 1;
        REPF(j, 1, N + 1) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j] * j) % M;
        }
    }
}
int f(int k) {
    int s = 0;
    REP(i, k + 1) {
        int tmp = dp[k][i] * bin_pow_mod(2, (N - k) * i) % M;
        s = (s + tmp) % M;
    }
    int t = bin_pow_mod(2, N - k, M - 1);
    return s * bin_pow_mod(2, t) % M;
}
signed main() {
    cin >> N >> M;
    init_fact();
    calc_dp();

    int ans = 0;
    REP(i, N + 1) {
        int tmp = combination(N, i) % M * f(i) % M;
        if (i % 2) {
            ans += M - tmp;
        } else {
            ans += tmp;
        }
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}


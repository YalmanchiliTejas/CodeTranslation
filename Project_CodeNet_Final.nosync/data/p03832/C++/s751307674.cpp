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
const signed INF_=1001001001; const int INF=1001001001001001001LL;
const int DX[9]={0,1,0,-1,1,1,-1,-1,0},DY[9]={-1,0,1,0,-1,1,1,-1,0};
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":"\n");return os;}
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
const int MAX_N=200005;
long long fact[MAX_N];
long long fact_inv[MAX_N];
long long bin_pow_mod(long long x,long long y) {
    if(x==0) return 0;
    long long prod=1;
    while(y>0) {
        if(y&1) {
            prod=(prod*x)%MOD;
        }
        x=(x*x)%MOD;
        y>>=1;
    }
    return prod%MOD;
}
struct init_fact {
    init_fact() {
        fact[0]=1, fact_inv[0]=1;
        for(int i=1;i<MAX_N;++i) {
            fact[i]=(fact[i-1]*i)%MOD;
            fact_inv[i]=bin_pow_mod(fact[i],MOD-2);
        }
    }
} init_fact;

int dp[1001][1001];
signed main() {
    int N=IN,A=IN,B=IN,C=IN,D=IN;
    dp[A-1][0]=1;
    REPF(i,A,B+1) {
        REP(j,N+1) {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
            REPF(k,C,D+1) {
                if(j<i*k) break;
                dp[i][j]+=dp[i-1][j-i*k]*fact[N-(j-i*k)]%MOD*fact_inv[N-j]%MOD*fact_inv[k]%MOD*bin_pow_mod(bin_pow_mod(fact[i],k),MOD-2)%MOD;
                dp[i][j]%=MOD;
            }
        }
    }
    cout<<dp[B][N]<<endl;
    return 0;
}

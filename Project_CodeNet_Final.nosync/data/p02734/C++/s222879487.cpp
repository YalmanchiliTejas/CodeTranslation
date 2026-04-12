#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef pair<double,double> PD;
typedef pair<int,P> ed;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 998244353;
const double eps = 1e-10;

struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%MOD+MOD)%MOD){}
  mint& fix() { x = (x%MOD+MOD)%MOD; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=MOD) x-=MOD; return *this;}
  mint& operator-=(const mint& a){ if((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=MOD; return *this;}
  mint operator^(int b) {mint res = 1;while(b > 0) {if(b&1) {res = (res*(*this));}*this=(*this)*(*this);b>>=1;} return res;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
typedef vector<mint> vm;
typedef vector<vm> vvm;
  
int main() {
  int N,s;
  cin >> N >> s;
  vi A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vvm dp(s+1,vm(3,0));
  dp[0][0] = 1;
  rep(i,N) {
    vvm dp2(s+1,vm(3,0));
    rep(j,s+1) {
      dp2[j][0]+=dp[j][0];
      dp2[j][1]+=dp[j][0]+dp[j][1];
      dp2[j][2]+=dp[j][0]+dp[j][1]+dp[j][2];
      if (j+A[i] <= s) {
        dp2[j+A[i]][1] += dp[j][0]+dp[j][1];
        dp2[j+A[i]][2] += dp[j][0]+dp[j][1];
      }
    }
    dp = dp2;
  }
  cout << dp[s][2].x << endl;
  return 0;
}
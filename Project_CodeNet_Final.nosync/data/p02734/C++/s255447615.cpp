#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
//const ll mod=1e9+7;
const ll mod=998244353;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint pow(ll t) const { if (!t) return 1; mint a = pow(t>>1); a *= a; if (t&1) a *= *this; return a; }
    // for prime mod
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
};

int main(){
  int n,s;
  cin >> n >> s;
  vector<ll> a(n);
  rep(i,n){ cin >> a[i]; }
  vector<vector<mint>> dp(3010, vector<mint>(3010,0));
  mint ans = 0;
  rep(i,n){ dp[i][0] = 1; }
  rep(i,n)rep(j,s+1){
    dp[i+1][j] += dp[i][j];
    if(a[i]<=j){
      dp[i+1][j] += dp[i][j-a[i]];
    }
    if(j==s){
      ans += dp[i+1][s]*(n-i);
      dp[i+1][s] = 0;
    }
  }
  cout << ans.x << endl;
  return 0;
}
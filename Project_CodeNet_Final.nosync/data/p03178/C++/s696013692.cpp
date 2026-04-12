#include <bits/stdc++.h>
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
constexpr char ln =  '\n';

const int mx=100010;
const ll mod=1e9+7;

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
  string s;
  int d;
  cin >> s >> d;
  int n = s.size();
  vector<vector<vector<mint>>> dp(10010, vector<vector<mint>>(2, vector<mint>(105,0)));
  dp[0][0][0]=1;
  rep(idx,n)rep(j,d)rep(k,2){
    int up = (int)(s[idx]-'0');
    rep(m,10){
      if(k==0 && up<m) continue;
      dp[idx+1][k|(m<up)][(m+j)%d] += dp[idx][k][j];
    }
  }
  mint ans = dp[n][0][0] + dp[n][1][0] -1; //without 0
  cout << ans.x << ln;
  return 0;
}
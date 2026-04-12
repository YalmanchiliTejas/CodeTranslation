#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = 998244353;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }


int main() {
  ll N, S; cin >> N >> S;
  ll A[N]; rep(i,N) cin >> A[i];
  ll dp[N+1][S+1] = {}; dp[0][0] = 1;
  rep(i,N) rep(j,S+1) {
    if (A[i]>S) dp[i+1][j] = dp[i][j];
    else if (A[i]==S) {
      if (j==S) dp[i+1][j] = ( dp[i][j] + dp[i][0]*(i+1)*(N-i) ) % MOD;
      else dp[i+1][j] = dp[i][j];
    }
    else {
      if (j==A[i]) dp[i+1][j] = ( dp[i][j] + dp[i][0] * (i+1) ) % MOD;
      else if (j==S) dp[i+1][j] = ( dp[i][j] + dp[i][j-A[i]] * (N-i) ) %MOD;
      else if (j<A[i]) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = ( dp[i][j] + dp[i][j-A[i]] ) % MOD;
    }
  }
  // rep(i,N+1) debug(dp[i], dp[i]+(S+1));
  ll result = dp[N][S];
  cout << result << endl;
  return 0;
}
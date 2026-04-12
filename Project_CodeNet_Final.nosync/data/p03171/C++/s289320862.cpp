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

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }


int main() {
  ll N; cin >> N;
  ll a[N]; rep(i,N) cin >> a[i];
  ll dp[2][N][N]; rep(i,2) rep(j,N) fill_n(dp[i][j],N,0);
  rep(i,N) { dp[0][i][i] = a[i]; dp[1][i][i] = -1*a[i]; }
  repr(i,1,N) rep(j,N-i) {
    dp[0][j][j+i] = max(a[j+i]+dp[1][j][j+(i-1)], a[j]+dp[1][j+1][j+i]);
    dp[1][j][j+i] = min(-1*a[j+i]+dp[0][j][j+(i-1)], -1*a[j]+dp[0][j+1][j+i]);
  }

  // rep(i,N) debug(dp[0][i],dp[0][i]+N);
  ll result = dp[0][0][N-1];
  cout << result << endl;
  return 0;
}
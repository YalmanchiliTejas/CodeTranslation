#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
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

ll pnk(ll n, ll k) {
  ll result = 1, pn = n, now = 0;
  while(k>=1<<now) {
    if (k&1<<now) result = result * pn % MOD;
    pn = pn * pn % MOD;
    now++;
  }
  return result;
}

int main() {
  ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  ll dp[B+1][N+1] = {}; dp[A-1][N] = 1;

  c_fac();
  repr(i,A,B+1) rep(j,N+1) {
    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
    ll con;
    for (ll k=C; j>=i*k&&k<=D; k++) {
      if (k==C) con = fac[j] * inv(pnk(fac[i],k)) % MOD * inv(fac[j-i*k]) % MOD * inv(fac[k]) % MOD;
      else con = con * nck(j-i*(k-1),i) % MOD * inv(k) % MOD;
      dp[i][j-i*k] = (dp[i][j-i*k] + dp[i-1][j]*con) % MOD;
    }
  }
  // rep(i,B+1) debug(dp[i],dp[i]+(N+1));

  ll result = dp[B][0];
  cout << result << endl;
  return 0;
}
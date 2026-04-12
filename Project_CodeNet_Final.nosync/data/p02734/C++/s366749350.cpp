/*input
3 4
2 2 4
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll MOD = 998244353;
const int SINF = 1000000009;
const ll INF =  1000000000000000018;

#define sp          cout << " "
#define nl          cout << "\n"
#define inv(a)      powr((a), (MOD - 2))
#define all(c)      (c).begin(),(c).end()
#define rep(i,a,b)  for(ll i = (a); i < (b); i ++)
#define prec(n)     cout << fixed << setprecision(n)
#define PI          3.14159265358979323846264338327951
#define ifalse      ios_base::sync_with_stdio(false), cin.tie(NULL)

template<typename T> void toInt(string s, T &a) { istringstream(s) >> a; }
ll gcd(ll a, ll b) { ll t; while(a) { t = a; a = b%a; b = t; } return b; }
ll sub(ll a, ll b) { a -= b; a = (a + MOD) % MOD; return a; }
ll mul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll add(ll a, ll b) { a += b; a %= MOD; return a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll powr(ll a, ll b) {
  ll x = 1LL;
  while(b) {
    if(b & 1) x = mul(x, a);
    a = mul(a, a), b >>= 1;
  }
  return x;
}

bool check(ll n)
{
  if(n == 1) return 0;
  if(n == 2 or n == 3) return 1;
  if(n%2 == 0 or n%3 == 0) return 0;
  for(ll i = 5; i*i <= n; i += 6) if(n%i == 0 or n % (i+2) == 0) return 0;
  return 1;
}

/*********************************START**********************************/
const int N = 3005;
int dp[N][N][3];

int main()
{
  ifalse;
  int n, s;
  cin >> n >> s;
  vector < int > a(n);
  for(auto &x: a) {
    cin >> x;
  }

  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j <= s; j ++) {
      dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][0]);
      dp[i + 1][j][1] = add(dp[i + 1][j][1], add(dp[i][j][0], dp[i][j][1]));
      dp[i + 1][j][2] = add(dp[i + 1][j][2], add(dp[i][j][0], add(dp[i][j][1], dp[i][j][2])));
      if(j + a[i] <= s) {
        dp[i + 1][j + a[i]][1] = add(dp[i + 1][j + a[i]][1], add(dp[i][j][0], dp[i][j][1]));
        dp[i + 1][j + a[i]][2] = add(dp[i + 1][j + a[i]][2], add(dp[i][j][0], dp[i][j][1]));
      }
    }
  }

  cout << dp[n][s][2], nl;
  return 0;
}
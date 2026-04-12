#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FR first
#define SC second
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, f, n) for(int i = (int)(f); i < (int)(n); i++)
#define each(a, b) for(auto& a : b)

typedef pair<int, int> P;

const int inf = 1LL << 55;
const int mod = 1e9 + 7LL;

int extgcd(int a, int b, int &x, int &y)
{
  int d = a;
  if(b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
  else x = 1, y = 0;
  return d;
}

int modinv(int a, int m)
{
  int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

int f[200020];
void fact()
{
  f[0] = 1;
  for(int i = 1; i < 200020; i++) {
    f[i] = f[i-1] * i % mod;
  }
}

int combi(int n, int k, int m)
{
  if(k < 0 || n < k) return 0;
  return f[n] * modinv(f[k] * f[n - k] % m, m) % m;
}

int dp[2002][2002];

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  fact();
  
  int N, D, X;
  while(cin >> N >> D >> X, N) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < min(D, N); i++) {
      for(int j = 0; j < N; j++) {
	dp[i+1][j+1] = (dp[i+1][j] + dp[i][j]) % mod;
	if(j+1 >= X) dp[i+1][j+1] = (dp[i+1][j+1] - dp[i][j+1-X] + mod) % mod;
      }
    }
    
    int ans = 0, nCk = 1;
    for(int i = 1; i <= min(N, D); i++) {
      // ans = (ans + dp[i][N] * combi(D, i, mod)) % mod;
      nCk = (nCk * ((D-i+1)%mod * modinv(i, mod)%mod)%mod) % mod;
      ans = (ans + dp[i][N] * nCk) % mod;
    }

    cout << ans << endl;
  }
  
  return 0;
}
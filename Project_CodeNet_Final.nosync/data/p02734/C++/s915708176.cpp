  #include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include<debug.h>
#else
#define db(...) 21
#endif

#define debug(x) cout << #x << " = " << x << endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;
const ll mod = 998244353;

inline int cmp(double x, double y = 0) 
{  
  if(fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

ll exp(ll a, ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

const int maxn = 3e3 + 10;

ll dp[maxn][maxn][3];
int n, s;

int a[maxn];

ll solve(int pos, int sum, int state)
{
  if(sum > s)
    return 0;

  if(pos == n || state == 2)
    return sum == s;
  
  ll &ans = dp[pos][sum][state];
  if(ans != -1)
    return ans;
  ans = 0;
  if(state == 0)
    ans += solve(pos + 1, 0, 0) + solve(pos, 0, 1);
  else if(state == 1)
    ans += solve(pos + 1, sum + a[pos], 1) + solve(pos + 1, sum, 1) 
         + solve(pos + 1, sum, 2);
  ans %= mod;
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  MSET(dp, -1);
  cin >> n >> s;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i];
  cout << solve(0, 0, 0) << endl;
  
  return 0;
}
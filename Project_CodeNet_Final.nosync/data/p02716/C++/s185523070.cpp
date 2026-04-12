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

const int maxn = 2e5 + 10;


ll a[maxn];
ll pref[maxn];
ll dp[maxn];

int main()
{
  int n;
  ios::sync_with_stdio(false);
  cin >> n;

  for(int i = 1 ; i <= n ; i++)
  {
    cin >> a[i];
  }

  pref[1] = a[1]; 

  for(int i = 3 ; i <= n ; i += 2)
  {
    pref[i] += pref[i - 2] + a[i];
  }

  for(int i = 2 ; i <= n; i++)
  {
    if(i & 1)
    {
      dp[i] = max(dp[i-1], dp[i-2] + a[i]);
    }
    else
    {
      dp[i] = max(dp[i - 2] + a[i], pref[i-1]);
    }
  }

  cout << dp[n] << endl;

  return 0;
}
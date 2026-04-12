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
const ll mod = 1e9 + 7;

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

const int maxn = 2e3 + 10;
ll fat[maxn], inv[maxn];

ll C(int n, int k)
{
  if(n < k) 
    return 0;
  if(n < 0 || k < 0) 
    return 0;
  return (((fat[n] * inv[k]) % mod) * inv[n - k]) % mod;
}

void initFactorials()
{
  fat[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < maxn; i++)
  {
    fat[i] = (fat[i-1] * i) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }
}

ll dp[maxn][3][5];
string s;
int k;


  
ll solve(int pos, bool tight , int cnt)
{

  if(cnt == k)
    return 1;
  if(pos == s.size())
    return 0;
  ll &ans = dp[pos][tight][cnt];
  if(ans != -1)
    return ans;
  ans = 0;
  int qt = tight ? s[pos] - '0' : 9;
  for(int i = 0; i <= qt; i++)
  {
    int newTight = (s[pos] - '0' == i)? tight : 0; 
    ans += solve(pos + 1, newTight, cnt + (i > 0));
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  MSET(dp, -1);
  cin >> s;
  cin >> k;
  cout << solve(0,1,0) << endl;
  return 0;
}
#include <bits/stdc++.h>
#define ll long long int
#define ii int
#define du double
#define jmp "\n"
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define printv(v)     \
  for (auto x : v)    \
    cout << x << " "; \
  cout << jmp;
#define vi vector<int>
#define vb vector<bool>
#define SORT(v) sort(v.begin(), v.end())
#define REV(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define SET(x, a) memset(x, a, sizeof(x))
#define si(x) x.size()
#define ff first
#define ss second
#define iin insert
#define deb(x) cout << "test " << #x << "=" << x << jmp
#define deb2(x, y) cout << "test " << #x << "=" << x << "," << #y << "=" << y << jmp
using namespace std;
const ll nax = 1e5 + 5;
const int M = 1e9 + 7;
ll mod(ll x)
{
  return ((x % M + M) % M);
}

ll add(ll a, ll b)
{
  return mod(mod(a) + mod(b));
}

ll mul(ll a, ll b)
{
  return mod(mod(a) * mod(b));
}

void solve()
{
  ll sum = 0, ans = 0, n;
  cin >> n;
  ll a[n];
  for (auto &x : a)
    cin >> x, sum += x;
  ll pre[n] ;
   pre[0] = a[0];
  for (ll i = 1; i < n; i++)
    pre[i] = add(pre[i - 1], a[i]);
  for (ll i = 0; i < n; i++)
  {
    ll temp = mul(a[i] , sum - pre[i]);
    ans = add(ans, temp);
  }
  cout << ans;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  //cin >> t;
  while (t--)
    solve();
  return 0;
}
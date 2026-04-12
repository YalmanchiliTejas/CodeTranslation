#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<lu> vu;
typedef vector<v> vv;
typedef vector<vu> vvu;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
typedef pair<lu, lu> puu;
typedef vector<puu> vpuu;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
  if (y > x) x = y;
#define amin(x, y) \
  if (y < x) x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
  if (f) yes else no;
#define noo \
  { no return; }

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template <typename T = ll>
vector<T> ga(ll n, bool oneIndexed = false) {
  vector<T> a = vector<T>(n + oneIndexed);

  for (ll i = 0; i < n; i++) {
    T p;
    cin >> p;
    a[i + oneIndexed] = p;
  }

  return move(a);
}

template <typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1) {
  if (end == -1) end = sz(a) - 1;
  for (ll i = begin; i <= end; i++) {
    // printf("%lu ", a[i]);
    cout << a[i] << " ";
  }
  cout << endl;
}

template <typename T, typename A>
void papair(vector<T, A> const &a, ll begin = 0, ll end = -1) {
  if (end == -1) end = sz(a) - 1;
  for (ll i = begin; i <= end; i++) {
    // printf("%lu ", a[i]);
    cout << a[i].first << " " << a[i].second << endl;
  }
}

pll dp[3010][3010];
void solve() {
  ll n;
  cin >> n;
  vector<ll> arr = ga(n);
  for (ll i = 0; i < n; i++) {
    dp[i][i].first = arr[i];
    dp[i][i].second = 0;
  }
  ll f = 0, l = n - 1;
  ll c = 0;
  ll x = 0, y = 0;
  for (ll i = 1; i < n; i++) {
    for (ll j = i - 1; j >= 0; j--) {
      if ((i - j) % 2 == 0) {
        if (dp[j + 1][i].first - dp[j + 1][i].second + arr[j] >=
            dp[j][i - 1].first - dp[j][i - 1].second + arr[i]) {
          dp[j][i].first = dp[j + 1][i].first + arr[j];
          dp[j][i].second = dp[j + 1][i].second;
        } else {
          dp[j][i].first = dp[j][i - 1].first + arr[i];
          dp[j][i].second = dp[j][i - 1].second;
        }
      } else {
        if (dp[j + 1][i].second - dp[j + 1][i].first + arr[j] >=
            dp[j][i - 1].second - dp[j][i - 1].first + arr[i]) {
          dp[j][i].first = dp[j + 1][i].first;
          dp[j][i].second = dp[j + 1][i].second + arr[j];
        } else {
          dp[j][i].first = dp[j][i - 1].first;
          dp[j][i].second = dp[j][i - 1].second + arr[i];
        }
      }
      //   cout << j << "-" << i << ' ';
      //   cout << dp[j][i].first << " " << dp[j][i].second << '\n';
    }
    // c++;
    // cout << '\n';
  }
  //   cout << dp[0][n - 1].first << " " << dp[0][n - 1].second << '\n';
  cout << (dp[0][n - 1].second - dp[0][n - 1].first) * ((n % 2 == 1) ? -1 : 1)
       << '\n';
  // if (dp[j][i - 1].first > dp[j + 1][i].first) {
  //   dp[i][j].first = dp[j + 1][i].first;
  //   dp[i][j].second = 0;
  // } else {
  //   dp[i][j].first = dp[j][i - 1].first;
  //   dp[i][j].second = 1;
  // }
  //   while (f != l) {
  //     if (c & 1) {
  //       y += ;
  //     } else {
  //       x += ;
  //     }
  //     if(dp[f][l].second==0)
  //     {

  //     }
  //     c++;
  //   }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // ll t;cin >> t;while(t--)
  solve();
  return 0;
}
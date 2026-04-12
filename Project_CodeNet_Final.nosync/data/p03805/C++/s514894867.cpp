#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound, __gcd, count, find, next_permutation
#include <bitset>    // bitset
#include <deque>     // deque
#include <iomanip>   // setprecsion
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <set>       // set
#include <stack>     // stack
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <utility>   // pair, make_pair
#include <vector>    // vector

#include <cassert> // assert
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>  // abs, sin, cos, tan
#include <ctime> // clock

// __builtin_popcountll

using namespace std;
using Graph = vector<vector<int>>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define mt(p, q, r) make_tuple(p, q, r)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;
typedef vector<tuple<ll, ll, ll>> vtlll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

template <typename T>
void fin(T a)
{
  cout << a << endl;
  exit(0);
}

void Main()
{
  ll n, m; cin >> n >> m;
  vll path(n);
  rep(i, n)
  {
    path[i] = i;
  }
  vvll loot(n);
  vll a(m), b(m);
  rep(i, m)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    loot[a[i]].pb(b[i]);
    loot[b[i]].pb(a[i]);
  }
  ll ans = 0;
  do
  {
    ll flag = 1;
    for(ll i = 0;i < n - 1;i++)
    {
      for(ll j = 0;j < loot[path[i]].size();j++)
      {
        if(path[i + 1] == loot[path[i]][j])
        {
          flag++;
          break;
        }
      }
    }
    if(flag == n&&path[0] == 0) ans++;
  } while (next_permutation(all(path)));
  fin(ans);
  return;
}

//前処理
int main()
{
  int ti = clock();
  srand((unsigned)time(NULL));
  ios::sync_with_stdio(false);
  cin.tie(0);
  //cout << fixed << setprecision(20); //高精度少数表示
  //cout << setfill('0') << internal << setw(4); //0埋め４桁
  Main();
  //printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC); // 実行時間計測
  return 0;
}
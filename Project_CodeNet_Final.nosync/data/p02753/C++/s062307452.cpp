#include <bits/stdc++.h>
//上記が使用不可な環境において
/*
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <iomanip>  //setprecsion
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <cmath>  //sin, cos, tan
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <complex>
#include <bitset>
#include <utility>
#include <functional>
*/
using namespace std;

//謎
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
typedef long long int ll;
typedef long long int lli;
typedef unsigned long long int ull;
typedef long double ld;
typedef string str;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
//謎
const int INF = INT_MAX;
const ll LLINF = 1LL << 60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

//0~nの範囲操作
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//1~nの範囲操作
#define rrep(i, n) for (ll i = 1; i <= (n); ++i)
#define irep(it, stl) for (auto it = stl.begin(); it != stl.end(); it++)
#define drep(i, n) for (ll i = (n)-1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl;
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define pb(n) push_back(n)
//謎
#define all(a) a.begin(), a.end()

//配列の合計
template <typename T>
T Sum(vector<T> n)
{
  return (accumulate(n.begin(), n.end(), 0));
}
template <>
ld Sum(vector<ld> n)
{
  return (accumulate(n.begin(), n.end(), 0.0));
}
//配列を昇順
template <typename T>
void Sort(T &n)
{
  sort(n.begin(), n.end());
}
//配列を降順
template <typename T>
void Reve(T &n)
{
  reverse(n.begin(), n.end());
}
//配列nをmにコピー
template <typename T, typename U>
void Copy(T &n, U &m)
{
  copy(n.begin(), n.end(), m.begin());
}
//小数点型に
template <typename T>
ld Cast(T &n)
{
  return static_cast<ld>(n);
}
//入力
template <typename T>
void Cin(T &n)
{
  cin >> n;
}
//配列入力
template <typename T>
void V(T &n)
{
  for (ll i = 0; i < n.size(); i++)
  {
    cin >> n[i];
  }
}
//２列配列入力
template <typename T, typename U>
void V(T &n, U &m)
{
  for (ll i = 0; i < n.size(); i++)
  {
    cin >> n[i] >> m[i];
  }
}
//３列配列入力
template <typename T, typename U, typename W>
void V(T &n, U &m, W &p)
{
  for (ll i = 0; i < n.size(); i++)
  {
    cin >> n[i] >> m[i] >> p[i];
  }
}
//yes, noと表示
void yn(bool a)
{
  if (a)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}
//Yes, Noと表示
void Yn(bool a)
{
  if (a)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
//YES, NOと表示
void YN(bool a)
{
  if (a)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
//yes, noと表示後終了
void fyn(bool a)
{
  if (a)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  exit(0);
}
//Yes, Noと表示後終了
void fYn(bool a)
{
  if (a)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  exit(0);
}
//YES, NOと表示後終了
void fYN(bool a)
{
  if (a)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  exit(0);
}
//AC, WAと表示
void AC(bool a)
{
  if (a)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
}
//AC, WAと表示後終了
void fAC(bool a)
{
  if (a)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
  exit(0);
}
//noneと表示後終了
void fnone(void)
{
  cout << "None" << endl;
  exit(0);
}
//Odd(奇数), Even(偶数)と表示後終了
void fOdd(bool a)
{
  if (a)
    cout << "Odd" << endl;
  else
    cout << "Even" << endl;
  exit(0);
}
//Possible, Impossibleと表示後終了
void Possible(bool a)
{
  if (a)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  exit(0);
}
//POSSIBLE, IMPOSSIBLEと表示後終了
void POSSIBLE(bool a)
{
  if (a)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  exit(0);
}
//四角　表示文字 a 縦幅 h 横幅 w
void square(char a, ll h, ll w)
{
  for (ll i = 0; i < h; i++)
  {
    for (ll j = 0; j < w; j++)
    {
      cout << a;
    }
    cout << endl;
  }
}
//四角枠　外周 a 中身 b 縦幅 h 横幅 w
void yoke(char a, char b, ll h, ll w)
{
  for (ll i = 0; i < h; i++)
  {
    for (ll j = 0; j < w; j++)
    {
      if (i == 0 || i == h - 1)
        cout << a;
      else if (j == 0 || j == w - 1)
        cout << a;
      else
        cout << b;
    }
    cout << endl;
  }
}
//四捨五入
ll C45(ll n)
{
  return (n + 1) / 2;
}
//文字列からcを探す
ll stcount(str s, char c)
{
  return count(s.cbegin(), s.cend(), c);
}
//素数
bool IsPrime(ll num)
{
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;
  long double sqrtNum = sqrt(num);
  for (ll i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)
      return false;
  }
  return true;
}
//桁数
ll GetDigit(ll num)
{
  return log10(num) + 1;
}
//各桁の和
ll KSum(ll n)
{
  ll sum = 0;
  if (n < 0)
    return 0;
  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
//数値反転
bool KReve(ll n)
{
  int reverse = 0;
  int remaind;
  int tmp = n;
  while (tmp != 0)
  {
    remaind = tmp % 10;
    reverse = reverse * 10 + remaind;
    tmp /= 10;
  }
  if (reverse == n)
    return true;
  else
    return false;
}
//約数全列挙
vector<ll> enum_div(ll n)
{
  vector<ll> ret;
  for (ll i = 1; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i != 1 && i * i != n)
      {
        ret.push_back(n / i);
      }
    }
  }
  return ret;
}
//最大公約数
ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}
//複数個の最大公約数
ll ngcd(vector<ll> a)
{
  ll res;
  res = a[0];
  for (ll i = 1; i < a.size() && res != 1; i++)
  {
    res = gcd(a[i], res);
  }
  return res;
}
//最小公倍数
ll lcm(ll a, ll b)
{
  return a * b / gcd(a, b);
}
//複数個の最小公倍数
ll nlcm(vector<ll> numbers)
{
  ll res;
  res = numbers[0];
  for (ll i = 1; i < numbers.size(); i++)
  {
    res = lcm(res, numbers[i]);
  }
  return res;
}
//累乗
ll Pow(ll x, ll n)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * x;
    x = x * x;
    n >>= 1;
  }
  return res;
}
//累乗(xのn乗%mod)
ll mod_pow(ll x, ll n, ll mod = MAX)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
//階乗
ll factorial(ll n)
{
  if (n > 0)
    return n * factorial(n - 1);
  else
    return 1;
}
//組み合わせ　nCr
ll comb(ll a, ll b)
{
  ll c;
  c = factorial(a) / (factorial(a - b) * factorial(b));
  return c;
}
//n ~ mの和
ll sigma(ll n, ll m)
{
  return ((n + m) * (m - n + 1) * 0.5);
}
//期待値
ld hope(ld a)
{
  return (sigma(1, a) / a);
}
//謎
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
//謎
/*
//幅優先探索
// 各座標に格納したい情報を構造体にする
// 今回はX座標,Y座標,深さ(距離)を記述している
struct Corr
{
  int x;
  int y;
  int depth;
};
queue<Corr> q;
int bfs(vector<vector<int>> grid)
{
  // 既に探索の場所を1，探索していなかったら0を格納する配列
  vector<vector<int>> ispassed(grid.size(), vector<int>(grid[0].size(), false));
  // このような記述をしておくと，この後のfor文が綺麗にかける
  int dx[8] = {1, 0, -1, 0};
  int dy[8] = {0, 1, 0, -1};
  while (!q.empty())
  {
    Corr now = q.front();
    q.pop();
    //今いる座標は(x,y)=(now.x, now.y)で，深さ(距離)はnow.depthである  ここで，今いる座標がゴール(探索対象)なのか判定する
    for (int i = 0; i < 4; i++)
    {
      int nextx = now.x + dx[i];
      int nexty = now.y + dy[i];

      // 次に探索する場所のX座標がはみ出した時
      if (nextx >= grid[0].size())
        continue;
      if (nextx < 0)
        continue;

      // 次に探索する場所のY座標がはみ出した時
      if (nexty >= grid.size())
        continue;
      if (nexty < 0)
        continue;

      // 次に探索する場所が既に探索済みの場合
      if (ispassed[nexty][nextx])
        continue;

      ispassed[nexty][nextx] = true;
      Corr next = {nextx, nexty, now.depth + 1};
      q.push(next);
    }
  }
}
//謎
//セグメント木
class Monoid
{
public:
  // 単位元
  ll unit;

  Monoid()
  {
    // 単位元
    unit = 0;
  }

  // 演算関数
  ll calc(ll a, ll b)
  {
    return a + b;
  }
};

class SegmentTree
{
public:
  // セグメント木の葉の要素数
  ll n;

  // セグメント木
  vector<ll> tree;

  // モノイド
  Monoid mono;

  SegmentTree(vector<ll> &v)
  {
    n = 1 << (ll)ceil(log2(v.size()));
    tree = vector<ll>(n << 1);
    for (ll i = 0; i < v.size(); i++)
    {
      update(i, v[i]);
    }
    for (ll i = v.size(); i < n; i++)
    {
      update(i, mono.unit);
    }
  }

  // k番目の値(0-indexed)をxに変更
  void update(ll k, ll x)
  {
    k += n;
    tree[k] = x;
    for (k = k >> 1; k > 0; k >>= 1)
    {
      tree[k] = mono.calc(tree[k << 1 | 0], tree[k << 1 | 1]);
    }
  }

  // [l, r)の最小値(0-indexed)を求める．
  ll query(ll l, ll r)
  {
    ll res = mono.unit;
    l += n;
    r += n;
    while (l < r)
    {
      if (l & 1)
      {
        res = mono.calc(res, tree[l++]);
      }
      if (r & 1)
      {
        res = mono.calc(res, tree[--r]);
      }
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
  ll operator[](ll k)
  {
    // st[i]で添字iの要素の値を返す
    if (k - n >= 0 || k < 0)
    {
      return -INF;
    }
    return tree[tree.size() - n + k];
  }

  void show()
  {
    int ret = 2;
    for (ll i = 1; i < 2 * n; i++)
    {
      cout << tree[i] << " ";
      if (i == ret - 1)
      {
        cout << endl;
        ret <<= 1;
      }
    }
    cout << endl;
  }
};
*/
//大文字->小文字(+32)

void Main()
{
  vc a(3);
  V(a);
  ll A = 0, B = 0;
  for(ll i = 0;i < 3;i++)
  {
    if(a[i] == 'A') {A++;}
    else {B++;}
  }
  if(A == 3||B == 3) fin("No")
  else fin("Yes")
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  //cout << fixed << setprecision(20);
  Main();
  return 0;
}
/*
//test時
g++ test.cpp -o a;./a
*/
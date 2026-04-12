/*
  Task: I. Kevin and Grid
  Link: http://codeforces.com/contest/1392/problem/I
  Lang: cpp17
*/
#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb push_back
#define INF LLONG_MAX
#define FLT_INF pow(10.0, 16)

using ll = long long;
using vll = vector<ll>;
using ull = unsigned long long;
using int2 = pair<ll, ll>;
using int3 = tuple<ll, ll, ll>;

template <typename A>
string to_string(const A &v);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(const pair<A, B> &p)
{
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(const tuple<A, B, C> &p)
{
  return "(" + to_string(std::get<0>(p)) + ", " + to_string(std::get<1>(p)) + ", " + to_string(std::get<2>(p)) + ")";
}

template <typename A>
string to_string(const A &v)
{
  bool first = true;
  string res = "{";
  for (const auto &x : v)
  {
    if (!first)
    {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename T>
void sort(vector<T> &val)
{
  sort(val.begin(), val.end());
}

template <typename T>
void reverse(vector<T> &val)
{
  reverse(val.begin(), val.end());
}

template <typename T>
void sort_b(vector<T> &val)
{
  sort(val.begin(), val.end(), greater<T>());
}

template <typename T>
T pair_sum(pair<T, T> &val)
{
  return val.first + val.second;
}

template <typename T>
T min(T a, T b, T c)
{
  return min(min(a, b), c);
}

template <typename T>
T max(T a, T b, T c)
{
  return max(max(a, b), c);
}

template <typename T>
T mul_mod(T a, T b, T mod)
{
  T res = 0;
  a %= mod;
  while (b)
  {
    if (b & 1)
    {
      res = (res + a) % mod;
    }
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) ;
#endif

#define COMMON_MOD pow(10, 9) + 7
#define PI 3.14159265

// sort(a.begin(), a.end(), less<ll>()); greater<ll>()
// cout<<fixed<<setprecision(20)<<(s/kl)*2;
/* printf("%lld %lld \n", cur_n, m / 2 + 1);
sort(a.begin(), a.end(), [ ](ll& lhs, ll& rhs) {return abs(lhs) < abs(rhs);});
*/

struct vertex
{
  vll childs;
  bool seen;
};

const vertex ZERO_VERTEX = {};

class tree
{
public:
  vector<vertex> verteces;

  tree(ll i)
  {
    verteces.assign(i, ZERO_VERTEX);
  }
};

struct node
{
  ll first;
  ll second;
  ll color;
  bool operator<(const node &a) const
  {
    return first < a.first;
  }

  bool operator>(const node &a) const
  {
    return first > a.first;
  }
};

string to_string(node a)
{
  return "{" + to_string(a.first) + ", " + to_string(a.second) + ", " + to_string(a.color) + "}";
}

class mytask
{
public:
  mytask() {}

  int solve()
  {
    ll n, x, m;
    cin >> n >> x >> m;
    ll res = 0;

    ll cur_x = x;
    ll i = 0;
    set<ll> seen;
    vll x_hst;
    while (i < n && seen.find(cur_x) == seen.end())
    {
      seen.insert(cur_x);
      res += cur_x;
      x_hst.pb(cur_x);
      cur_x = ((cur_x * cur_x) % m);
      i++;
    }

    if (i == n)
    {
      cout << res;
      return 0;
    }

    ll circle_sum = res;
    ll circle_len = i;
    ll prefix_sum = 0;
    ll prefix_len = 0;

    ll j = 0;
    while (x_hst[j] != cur_x)
    {

      circle_len--;
      circle_sum -= x_hst[j];
      prefix_sum += x_hst[j];
      prefix_len++;

      j++;
    }

    res = prefix_sum;
    n -= prefix_len;
    res += circle_sum * (n / circle_len);
    n %= circle_len;
    for (ll i = 0; i < n; i++)
    {
      res += x_hst[i + j];
    }

    cout << res;

    // for (ll i = 0; i < n; i++)
    // {
    //   debug(x);
    //   res += x;
    //   x = ((x * x) % m);
    // }

    return 0;
  }
};

int main()
{

  ios::sync_with_stdio(false);
  cin.tie(0);

  auto task = mytask();
  task.solve();

  //cout << endl;

  return 0;
}
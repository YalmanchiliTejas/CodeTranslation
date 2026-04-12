#define STOPIT
#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

void debug_impl() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { cerr << " " << head; debug_impl(tail...); }
#ifndef STOPIT
    #define debug(...)\
    do {\
        cerr << boolalpha << "[" << #__VA_ARGS__ << "]:";\
        debug_impl(__VA_ARGS__);\
        cerr << std::noboolalpha;\
    } while (false)
#else
    #define debug(...) {}
#endif

template < typename Container, typename Value = typename Container::value_type, enable_if_t<!is_same< Container, string >::value, nullptr_t> = nullptr>
istream& operator>> (istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, enable_if_t<!is_same< Container, string >::value, nullptr_t> = nullptr >
ostream& operator<< (ostream& os, Container const& v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}
const ll INF = 100000000000000000;


void update_dp(
    int y1, int x1, int y2, int x2, 
    vector<vector<ll>> &dp, 
    const vector<vector<int>> &minmax,
    const vector<ll> &values)
{
  int require = minmax[y2][x2];
  int now = minmax[y1][x1];
  // initial point
  if (x1<0)
  {
    if (require == 1)
      dp[y2][x2] = max(dp[y2][x2], values[x2]);
    return;
  }

  if (require == now)
  {
    dp[y2][x2] = max(dp[y2][x2], dp[y1][x1]);
    return;
  }
  if (require - now >1)
    return;
  
  if (x2-x1==1) return;
  dp[y2][x2] = max(dp[y2][x2], dp[y1][x1]+values[x2]);
}

void solve(vector<ll> values, int n)
{
  // min/ max counts 
  vector<vector<int>> minmax(2, vector<int>(n, 0));
  rep(i, 0, n)
  {
    // min
    minmax[0][i] = n/2 - (n-i-1)/2;
    // max
    minmax[1][i] = (i+2)/2;
  }
  debug(minmax);

  // dynamic programming
  vector<vector<ll>> dp(2, vector<ll>(n, -INF));
  ll res = -INF;
  dp[1][0] = values[0];
  rep(i, 0, n)
  {
    rep(j, 1, 4)
      rep(k, 0, 2)
      {
        update_dp(k, i-j, 0, i, dp, minmax, values);
        update_dp(k, i-j, 1, i, dp, minmax, values);
      }
    debug(i, dp[0][i], dp[1][i]);

    if (minmax[0][i] == n/2)
      res = max(res, dp[0][i]);
    if (minmax[1][i] == n/2)
      res = max(res, dp[1][i]);
  }
  cout << res << endl;
}

int main()
{
  int n;
  cin >> n;
  vector<ll> values(n);
  rep(i, 0, n) cin >> values[i];

  solve(values, n);
  return 0;
}

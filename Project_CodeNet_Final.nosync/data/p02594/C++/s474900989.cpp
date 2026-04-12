/*

Coded and Decoded by : Yash Kapoor

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// s.find_by_order(index);
// s.order_of_key(value);

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mp make_pair
#define pll pair<ll, ll>
#define vl vector<ll>
#define sl set<ll>
#define vll vector<pll>
#define ml map<ll, ll>
#define mll map<pll, ll>
#define all(a) a.begin(), a.end()
#define x first
#define y second
#define sz(x) (ll) x.size()
#define dl '\n'
#define why (ll)1000000007
//#define why         (ll)998244353
#define lp(i, a, b) for (ll i = a; i < b; ++i)
#define lpr(i, a, b) for (ll i = a; i >= b; i--)
#define lpd(i, x) for (auto i : x)
#define ios                                                                                                            \
  ios_base::sync_with_stdio(false);                                                                                    \
  cin.tie(0);                                                                                                          \
  cout.tie(0);

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

ll inf = 1e18;
ld pi = 3.141592653589;
ll mod = why;
ll fast_power(ll base, ll power, ll mod)
{
  ll result = 1;
  while (power) {
    if (power % 2)
      result = (result * base) % mod;
    base = (base * base) % mod;
    power /= 2;
  }
  return result;
}

ll inverse(ll base, ll mod) { return fast_power(base, mod - 2, mod); }
int test = 1;
void solve() 
{
  ll n; cin >> n;
  if( n >= 30 )
    cout << "Yes" ;
else cout << "No";
}

int main()
{
  // #ifndef ONLINE_JUDGE 
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif
  ios 
  ll t = 1;
  //cin >> t;
  while (t--) 
  {
    //cout << "Case #" << test++ << ": ";
    solve();
  }
}
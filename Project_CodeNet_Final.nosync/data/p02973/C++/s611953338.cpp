#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
ll INF = 1e18;

int main() {
  //
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  multiset<ll> s;
  s.insert(a[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    multiset<ll>::iterator it = s.upper_bound(a[i]);
    if (it == s.end()) {
      s.insert(a[i]);
    } else {
      // cout << a[i] << "<" << *it << endl;
      s.erase(it);
      s.insert(a[i]);
    }
  }
  cout << s.size() << endl;
  return 0;
}

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

const ll INF = 1LL << 50;

const ll mod = 1000000007;

int main() {
  ll n;
  cin >> n;
  dqll l;
  rep(i, n) {
    ll t;
    cin >> t;
    l.push_back(t);
  }
  Sort(l);

  dqll lcp = l;

  ll ans = 0;
  ll m = l.front();
  l.pop_front();
  ll pr = m, pl = m;
  ll turn = 0;
  while (!l.empty()) {
    if(l.size() == 1){
      ans += max(abs(pr - l.front()), abs(pl - l.front()));
      break;
    }
    if(turn == 0){
      ans += abs(pr - l.back());
      pr = l.back();
      l.pop_back();
      ans += abs(pl - l.back());
      pl = l.back();
      l.pop_back();
    } else {
      ans += abs(pr - l.front());
      pr = l.front();
      l.pop_front();
      ans += abs(pl - l.front());
      pl = l.front();
      l.pop_front();
    }
    turn = 1 - turn;
    //cout << ans << endl;
  }

  ll ansb = 0;
  m = lcp.back();
  lcp.pop_back();
  pr = m, pl = m;
  turn = 1;
  while (!lcp.empty()) {
    if(lcp.size() == 1){
      ansb += max(abs(pr - lcp.front()), abs(pl - lcp.front()));
      break;
    }
    if(turn == 0){
      ansb += abs(pr - lcp.back());
      pr = lcp.back();
      lcp.pop_back();
      ansb += abs(pl - lcp.back());
      pl = lcp.back();
      lcp.pop_back();
    } else {
      ansb += abs(pr - lcp.front());
      pr = lcp.front();
      lcp.pop_front();
      ansb += abs(pl - lcp.front());
      pl = lcp.front();
      lcp.pop_front();
    }
    turn = 1 - turn;
    //cout << ans << endl;
  }


  cout << max(ans, ansb) << endl;

  return 0;
}

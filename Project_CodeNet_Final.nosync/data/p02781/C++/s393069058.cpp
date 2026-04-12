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

ll rec(string n, ll b, ll k) {
  if (k == 0) return 1LL;
  if ((ll)n.length() < k) return 0;
  if (n == "") return 1LL;

  ll ans = 0;
  string nn = n.size() >= 2 ? n.substr(1, n.size() - 1) : "";
  ll d = n[0] - '0';
  if (b == 0) {
    if(d == 0){
      ans += rec(nn, 0, k);
    } else {
      ans += rec(nn, 0, k-1);
      ans += rec(nn, 1, k);
      ans += (d-1)*rec(nn, 1, k-1);
    }
  } else {
    ans += rec(nn, 1, k);
    ans += 9*rec(nn, 1, k-1);
  }
  return ans;
}

int main() {
  string n;
  ll k;
  cin >> n >> k;

  ll ans = rec(n, 0LL, k);

  cout << ans << endl;

  return 0;
}

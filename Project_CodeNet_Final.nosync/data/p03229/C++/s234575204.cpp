#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int n;
  cin >> n;
  deque<int> deq;
  rep(i, n) {
    int a;
    cin >> a;
    deq.push_back(a);
  }
  sort(deq.begin(), deq.end());
  vector<ll> high, low;
  bool b = 0;
  while (!deq.empty()) {
    if (b) {
      high.push_back(deq.back());
      deq.pop_back();
    } else {
      low.push_back(deq.front());
      deq.pop_front();
    }
    b ^= 1;
  }
  ll ans = 0;
  if (n%2) {
    rep(i, high.size())
      ans += high[i]*2;
    ans += low.back()+low[low.size()-2];
    rep(i, low.size())
      ans -= low[i]*2;
    high.push_back(low.back());
    low.pop_back();
    ll tmp = 0;
    rep(i, low.size())
      tmp -= low[i]*2;
    tmp -= high.back()+high[high.size()-2];
    rep(i, high.size())
      tmp += high[i]*2;
    chmax(ans, tmp);
  } else {
    rep(i, high.size()-1)
      ans += high[i]*2;
    ans += high.back()+low.back();
    rep(i, low.size())
      ans -= low[i]*2;
  }
  cout << ans << endl;
  return 0;
}
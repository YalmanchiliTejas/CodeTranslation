#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const ll INF = 1LL << 60;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int N;
vector<pii> balls;
ll max_val,min_val;
int main() {
  max_val = 0;
  min_val = INF;
  cin >> N;
  balls.resize(N);
  for (auto &val : balls){
    cin >> val.first >> val.second;
    if(val.first > val.second){
      swap(val.first, val.second);
    }
    max_val = max(max_val, (ll)val.first);
    max_val = max(max_val, (ll)val.second);

    min_val = min(min_val, (ll)val.first);
    min_val = min(min_val, (ll)val.second);
  }
  sort(balls.begin(), balls.end());
  ll result = INF;
  //R_max = max_val, B_min = min_val
  {
    ll R_max,R_min;
    ll B_max,B_min;
    R_max = 0;
    R_min = INF;

    B_max = 0;
    B_min = INF;
    for (const auto &val : balls){
      ll a = val.first;
      ll b = val.second;
      ll big = max(a, b);
      ll small = min(a, b);
      R_max = max(R_max, big);
      R_min = min(R_min, big);
      B_max = max(B_max, small);
      B_min = min(B_min, small);
    }
    result = min(result, (R_max - R_min) * (B_max - B_min));
  }
  //R_max = max_val, R_min = min_val
  {
    ll B_max,B_min;
    B_max = 0;
    B_min = INF;
    ll val1 = (max_val - min_val);
    map<ll, int> R,B;
    for (const auto &val : balls){
      R[val.first]++;
      B[val.second]++;
    }
    for (int i = N - 1; i >= 0; i--){
      pii p = balls[i];
      int a = p.first;//pre R
      int b = p.second;//pre B
      R[a]--;
      B[b]--;
      if (R[a] == 0){
        R.erase(a);
      }
      if (B[b] == 0){
        B.erase(b);
      }
      R[b]++;
      B[a]++;

      B_max = (*B.rbegin()).first;
      B_min = (*B.begin()).first;
      // cout << B_max << " " << B_min << endl;
      result = min(result, val1 * (B_max - B_min));
    }
  }
  cout << result << endl;
  return 0;

}

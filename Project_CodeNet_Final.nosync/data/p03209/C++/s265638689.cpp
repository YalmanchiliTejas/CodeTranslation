#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  long long x; cin >> x;
  vector<long long> height(n+1);
  height[0] = 1;
  FOR(i, 1, n+1) {
    height[i] = height[i-1] * 2;
    height[i] += 3;
  }
  vector<long long> meet(n+1);
  meet[0] = 0;
  FOR(i, 1, n+1) {
    meet[i] = meet[i-1] * 2;
    meet[i] += 1;
  }
  long long ans = 0;
  for (int i = n; i >= 0; --i) {
    if (height[i] == x) {
      ans += meet[i] * 2 + 1;
      break;
    } else if (height[i]/2+1 == x) {
      ans += meet[i] + 1;
      break;
    } else if (height[i]/2+1 < x) {
      ans += meet[i] + 1;
      x -= height[i]/2+1;
    } else {
      --x;
    }
  }
  cout << ans << '\n';
  return 0;
}

// For AtCoder Problems
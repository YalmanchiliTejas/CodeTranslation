#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <chrono>
#include <ctime>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, X; cin >> N >> X;

  vector<ll> vec(51);
  vector<ll> cnt(51);
  vec.at(0) = 1;
  cnt.at(0) = 1;
  for(int i=1; i<=50; i++) {
    vec.at(i) = vec.at(i-1)*2 + 3;
    cnt.at(i) = cnt.at(i-1)*2 + 1;
  }

  debugln(vec.at(50));
  debugln(cnt.at(50));

  ll ans = 0;

  for(int i=N; i>=0; i--) {
    if (X >= vec.at(i)) {
      ans += cnt.at(i);
      break;
    }
    if (i == 0) continue;
    if (X >= vec.at(i-1)+2) {
      X -= vec.at(i-1)+2;
      ans += cnt.at(i-1)+1;
    } else if (X == vec.at(i-1)+1) {
      ans += cnt.at(i-1);
      break;
    } else if (X >= 1) {
      X--;
    } else {
      break;
    }
    debug(i);
    debugln(X);
  }
  cout << ans << endl;
}
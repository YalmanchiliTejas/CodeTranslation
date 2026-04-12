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
#include <bitset>
#include <iterator>
#include <cmath>
#include <stack>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

constexpr ll mod = 1e9 + 7;
const double PI = acos(-1.0);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w; cin >> h >> w;
  auto cnt = 0;
  rep(i, h*w) {
    char c; cin >> c;
    if (c == '#') {
      cnt++;
    }
  }
  if (cnt == h+w-1) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}

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

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const ll mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<string> s(n);
  rep(i, n) {
    cin >> s.at(i);
  }
  int mat[n][26];
  rep(i, n) {
    rep(j, 26) {
      mat[i][j] = 0;
    }
  }
  rep(i, n) {
    int size = s.at(i).size();
    rep(j, size) {
      mat[i][s.at(i).at(j)-'a']++;
    }
  }

  rep(j, 26) {
    int mi = INT_MAX;
    rep(i, n) {
      mi = min(mi, mat[i][j]);
    }
    rep(i, mi) {
      cout << (char)('a' + j);
    }
  }
  cout << endl;

}
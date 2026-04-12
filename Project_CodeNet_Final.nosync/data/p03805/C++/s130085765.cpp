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

  int n; int m; cin >> n >> m;
  bool graph[9][9];
  rep(i, 9) {
    rep(j, 9) {
      graph[i][j] = false;
    }
  }
  rep(i, m) {
    int a, b; cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  vector<int> vec;
  for(int i=2; i<=n; i++) {
    vec.push_back(i);
  }

  //debugln(vec.size());

  int ans = 0;
  do {
    int b = 1;
    bool flag = true;
    for(auto e : vec) {
      //debugln(e);
      if(graph[b][e]) {
        b = e;
      } else {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  } while (next_permutation(vec.begin(), vec.end()));
  
  cout << ans << endl;
}
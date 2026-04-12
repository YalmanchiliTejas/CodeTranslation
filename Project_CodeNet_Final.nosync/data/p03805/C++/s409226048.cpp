#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

bool G[8][8];

bool check(const vector<int> v) {
  int i = 0;
  for (int j : v) {
    if (!G[i][j]) {
      return false;
    }
    i = j;
  }
  return true;
}

int main() {
  int N, M; cin >> N >> M;
  vector<int> ids(N-1);
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b; --a, --b;
    G[a][b] = true;
    G[b][a] = true;
  }
  for (int i = 0; i < N-1; ++i) {
    ids[i] = i + 1;
  }

  int cnt = 0;
  do {
    if (check(ids)) ++cnt;
  } while (next_permutation(ids.begin(), ids.end()));
  cout << cnt << endl;
}

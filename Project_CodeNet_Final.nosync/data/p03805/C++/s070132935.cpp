// Last Change: 09/10/2019 14:17:46.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<set<int>> edge(N, set<int>());

  {
    int a, b;
    for (int i = 0; i < M; ++i) {
      cin >> a >> b;
      --a, --b;
      edge[a].insert(b);
      edge[b].insert(a);
    }
  }

  vector<int> perm(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    perm[i] = i + 1;
  }

  ll ans = 0;
  do {
    bool flag = true;

    if (edge[0].count(perm[0]) == 0) {
      flag = false;
    }

    for (int i = 0; i < N - 2; ++i) {
      if (edge[perm[i]].count(perm[i + 1]) == 0) {
        flag = false;
      }
    }

    if (flag) {
      ++ans;
    }
  } while (next_permutation(perm.begin(), perm.end()));

  cout << ans << endl;
}

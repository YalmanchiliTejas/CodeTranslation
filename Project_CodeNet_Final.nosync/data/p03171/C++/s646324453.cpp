#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int N;
vector<ll> A;
ll cache[3000][3000];

ll dfs(int l, int r, int turn = 0) {
  if (turn == N - 1) {
    if (turn % 2 == 0) {
      return A[l];
    } else {
      return -A[l];
    }
  }

  if (cache[l][r] != -1) {
    return cache[l][r];
  }

  if (turn % 2 == 0) {
    ll v1 = A[l] + dfs(l + 1, r, turn + 1);
    ll v2 = A[r] + dfs(l, r - 1, turn + 1);

    return cache[l][r] = max(v1, v2);
  } else {
    ll v1 = dfs(l + 1, r, turn + 1) - A[l];
    ll v2 = dfs(l, r - 1, turn + 1) - A[r];

    return cache[l][r] = min(v1, v2);
  }
}

int main() {
  memset(cache, -1, sizeof(cache));
  cin >> N;

  ll a;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    A.push_back(a);
  }

  cout << dfs(0, N - 1) << endl;

  return 0;
}

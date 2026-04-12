#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  while (cin >> N) {
    vector<pair<int, int>> X(N);
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      X[i] = make_pair(x, i);
    }
    sort(X.begin(), X.end());
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
      if ((N - 1) / 2 < i) {
        ans[X[i].second] = X[(N - 1) / 2].first;
      } else {
        ans[X[i].second] = X[(N - 1) / 2 + 1].first;
      }
    }
    for (int x : ans) {
      cout << x << endl;
    }
  }
  return 0;
}

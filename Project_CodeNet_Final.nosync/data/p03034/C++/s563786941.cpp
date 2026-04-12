#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];
  ll ans = 0;
  for (int d = 1; d <= N - 1; d++) {
    set<int> st;
    int l = 0;
    int r = N - 1;
    ll cost = 0;
    while (l < N - 1 && r > d) {
      if (!st.insert(l).second) break;
      if (!st.insert(r).second) break;
      cost += S[l] + S[r];
      l += d;
      r -= d;
      ans = max(ans, cost);
    }
  }
  cout << ans << '\n';
}

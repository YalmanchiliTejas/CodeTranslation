#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> S(N);
  REP(i, N) cin >> S[i];
  vector<vector<int>> divs(N + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      divs[j].push_back(i);
    }
  }
  const long long INF = 1e18;

  vector<vector<pair<int, long long>>> back(N);
  vector<vector<pair<int, long long>>> front(N);
  for (int d = 1; d <= N - 1; d++) {
    {
      int x = N - 1;
      long long s = 0;
      while (x >= 0) {
        s += S[x];
        back[d].emplace_back(x, s);
        x -= d;
      }
      reverse(back[d].begin(), back[d].end());
    }
    {
      int x = 0;
      long long s = 0;
      while (x <= N - 1) {
        s += S[x];
        front[d].emplace_back(x, s);
        x += d;
      }
    }
  }

  auto check = [&](int a, int b) {
    if (a <= b || b <= 0) return -INF;
    if (a % (a - b) == 0) {
      long long k = a / (a - b);
      if ((a - b) * (k - 1) + a < N - 1) return -INF;
    }
    long long res = 0;
    res += lower_bound(back[a - b].begin(), back[a - b].end(), make_pair(a, -INF))->second;
    res += lower_bound(front[a - b].begin(), front[a - b].end(), make_pair(N - 1 - a, -INF))->second;
    return res;
  };
  long long ans = 0;
  for (int A = 1; A <= N - 1; A++) {
    for (int k : divs[N - 1 - A]) {
      int B = A - (N - 1 - A) / k;
      ans = max(ans, check(A, B));
    }
  }
  cout << ans << '\n';
}

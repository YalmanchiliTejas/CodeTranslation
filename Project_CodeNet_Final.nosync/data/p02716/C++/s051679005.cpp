#include <bits/stdc++.h>
using namespace std;

// dp[i]
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  vector<int> v(N);
  for (int i = 0; i < N; ++i) cin >> v[i];
  if (N == 2) {
      cout << max(v[0], v[1]) << endl;
      return 0;
  }

  if (N & 1) {
    vector<long long> dp0(N, 0);
    vector<long long> dp1(N, 0);
    vector<long long> dp2(N, 0);
    for (int i = 0; i < N; ++i) {
      dp0[i] = (i-2>=0 ? dp0[i-2] : 0) + v[i];
      dp1[i] = max((i-3>=0 ? dp0[i-3] : 0), (i-2>=0 ? dp1[i-2] : 0)) + v[i];
      dp2[i] = max({
        (i-4>=0 ? dp0[i-4] : 0),
        (i-3>=0 ? dp1[i-3] : 0),
        (i-2>=0 ? dp2[i-2] : 0)
      }) + v[i];
    }
    cout << max({dp0[N-3], dp1[N-2], dp2[N-1]}) << endl;
  } else {
    vector<long long> dp(N);
    dp[N - 1] = v[N - 1];
    for (int i = N - 3; i >= 0; i -= 2) {
      dp[i] = dp[i + 2] + v[i];
    }
    long long sum = 0;
    long long result = dp[1];
    for (int i = 0; i < N; i += 2) {
        sum += v[i];
        result = max(result, sum + (i+3<N ? dp[i+3] : 0));
    }
    cout << result << endl;
  }

  return 0;
}
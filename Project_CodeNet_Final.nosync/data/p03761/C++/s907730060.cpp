#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N; scanf("%d", &N);
  vector<string> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  vector<vector<int>> freqs(N, vector<int>(128, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < (int)S[i].size(); ++j) {
      ++freqs[i][S[i][j]];
    }
  }

  string ans;
  for (int c = 'a'; c <= 'z'; ++c) {
    int cnt = INF;
    for (int i = 0; i < N; ++i) {
      cnt = min(cnt, freqs[i][c]);
    }
    ans += string(cnt, c);
  }
  printf("%s\n", ans.c_str());
  return 0;
}

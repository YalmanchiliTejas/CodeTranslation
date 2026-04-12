#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;

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
      ++freqs[i][S[i][j] - 'a'];
    }
  }

  string ans = "";
  for (int i = 0; i < 26; ++i) {
    int cnt = INF;
    for (int j = 0; j < N; ++j) {
      cnt = min(cnt, freqs[j][i]);
    }
    if (cnt > 0) {
      ans += string(cnt, (char)('a' + i));
    }
  }
  printf("%s\n", ans.c_str());
  return 0;
}

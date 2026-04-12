#include <bits/stdc++.h>
using namespace std;

const string SW = "SW";

int main() {
  int N; cin >> N;
  string s; cin >> s;;
  string ans[] = {"SS", "SW", "WS", "WW"};
  int ok = -1;
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j < N; ++j) {
      ans[i] += SW[(s[j] == 'o') ^ (ans[i][j - 1] == ans[i][j])];
    }
    if (ans[i][0] == ans[i][N]) {
      if ((s[0] == 'o') ^ (ans[i][0] == 'S') ^ (ans[i][1] == ans[i][N - 1])) ok = i;
    }
  }
  if (ok == -1) {
    cout << -1 << endl;
  } else {
    cout << ans[ok].substr(0, N) << endl;
  }
  return 0;
}

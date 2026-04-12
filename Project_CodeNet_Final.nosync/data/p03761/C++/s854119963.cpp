#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

const int ALPHABET = 26;
const int N = 55;

signed main() {
  int n;
  cin >> n;

  vector<vector<int>> cnt(n, vector<int> (ALPHABET));
  rep(i,n) {
    string s;
    cin >> s;

    int m = s.size();
    for (int j = 0; j < m; j++) {
      int idx = s[j] - 'a';
      cnt[i][idx]++;
    }
  }

  vector<int> minimum(ALPHABET, N);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < ALPHABET; j++) {
      minimum[j] = min(minimum[j], cnt[i][j]);
    }
  }

  string answer = "";
  for (int i = 0; i < ALPHABET; i++) {
    answer += string(minimum[i], (i + 'a'));
  }

  cout << answer << endl;

}


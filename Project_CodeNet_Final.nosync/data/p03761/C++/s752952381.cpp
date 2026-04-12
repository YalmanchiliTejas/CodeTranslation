#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> S(n);
  vector<int> cnt(26, INT_MAX);
  rep(i, n) cin >> S[i];
  rep(i, n) {
    for(int j=0; j<26; ++j) {
      int tmp = 0;
      for(char c:S[i]) {
        if(c-'a' == j) ++tmp;
      }
      cnt[j] = min(cnt[j], tmp);
    }
  }
  rep(i, 26) {
    rep(j, cnt[i]) {
      cout << (char)(i+'a');
    }
  }
  cout << endl;
  return 0;
}

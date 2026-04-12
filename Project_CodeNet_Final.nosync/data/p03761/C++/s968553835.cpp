// Undone
#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;
signed main() {
  int N; cin >> N;
  vector<int> ans(26, INF);
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for (int j = 0; j < s.length(); j++) {
      cnt[s[j]-'a']++;
    }

    for (int j = 0; j < ans.size(); j++) {
      ans[j] = min(ans[j], cnt[j]);
    }
  }
  
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i]; j++) {
      cout << (char)(i+'a');
    }
  }
  cout << endl;
}

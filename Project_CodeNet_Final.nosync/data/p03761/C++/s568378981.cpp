#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> cnt('z' - 'a' + 1, INT_MAX);
  for (int j = 0; j < n; ++j) {
    string e;
    cin >> e;
    for (size_t i = 0; i < cnt.size(); ++i) {
      cnt[i] = min(cnt[i], (int)count(e.begin(), e.end(), 'a' + i));
    }
  }
  string ans;
  for (size_t i = 0; i < cnt.size(); ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      ans.push_back('a' + i);
    }
  }
  cout << ans << "\n";
}

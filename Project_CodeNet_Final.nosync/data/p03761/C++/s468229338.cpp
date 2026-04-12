#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) (v).begin(), (v).end()

const int ALPHABET_NUM = 26;

int main()
{
  int n; cin >> n;
  vector<map<int, int>> mps(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;

    for (int j = 0; j < s.size(); ++j) {
      mps[i][s[j]-'a']++;
    }
  }

  vector<int> ans(ALPHABET_NUM, 1e9);
  for (int j = 0; j < ALPHABET_NUM; ++j) {
    for (int i = 0; i < n; ++i) {
      ans[j] = min(ans[j], mps[i][j]);
    }
  }

  for (int i = 0; i < ALPHABET_NUM; ++i) {
    cout << string(ans[i], 'a' + i);
  }
}
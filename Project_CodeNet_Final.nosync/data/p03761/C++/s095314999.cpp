#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; 
  cin >> n;
  vector<map<char, int>> hash(n);
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (auto &c : s) hash[i][c]++;
  }
  for (char i = 'a'; i <= 'z'; ++i) {
    int mn = 1e9;
    for (int j = 0; j < n; ++j) {
      if (hash[j][i] < mn) 
        mn = hash[j][i];
    }
    if (mn > 0) cout << string(mn, i);
  }
  cout << endl;

  return 0;
}


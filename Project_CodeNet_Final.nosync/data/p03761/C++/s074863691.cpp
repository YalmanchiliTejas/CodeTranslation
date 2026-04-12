#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vector<string> a(n);
  for (string &i : a) cin >> i;
  vector<vector<int>> f(n, vector<int>(26, 0));
  for (int i = 0; i < n; i++) {
    for (char c : a[i]) {
      f[i][c - 'a'] += 1;
    }
  }
  for (int i = 0; i < 26; i++) {
    int maxi = 100;
    for (int j = 0; j < n; j++) {
      maxi = min(maxi, f[j][i]);
    }
    for (int j = 0; j < maxi; j++) {
      cout << char(i + 'a');
    }
  }
  cout << endl;
  return 0;
}

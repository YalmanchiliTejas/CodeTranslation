#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1000000007;
#define Sort(a) sort(a.begin(), a.end())

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  string s;
  vector<vector<int>> a(26, vector<int>(n));
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      a[s[j]-97][i]++;
    }
  }
  int b[26] = {0};
  for (int i = 0; i < 26; i++) {
    if (n == 1) {
      b[i] = a[i][0];
    }
    else {
      for (int j = 0; j < n-1; j++) {
        if (j == 0) {
          b[i] = min(a[i][j], a[i][j+1]);
        }
        else {
          b[i] = min(b[i], a[i][j+1]);
        }
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < b[i]; j++) {
      cout << char(97 + i);
    }
  }
  cout << '\n';
}
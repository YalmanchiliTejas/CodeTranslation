#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  string s;
  cin >> s;
  for (int i = 0; i + 1 < s.size(); i++) {
    if (s[i] == 'A' && s[i+1] == 'C') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
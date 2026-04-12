#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;

  int cnt = 0;
  for (char c : s) {
    if (c == 'A') cnt++;
  }

  if (cnt == 0 || cnt == 3) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
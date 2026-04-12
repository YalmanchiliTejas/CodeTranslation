#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<char> a(n);
  for (int i = 0; i < n; i ++) cin >> a[i];

  char ans = a[0];
  for (int i = 1; i < n; i ++) {
    if (ans == 'F') ans = 'T';
    else if (a[i] == 'T') ans = 'T';
    else ans = 'F';
  }

  cout << ans << endl;
}


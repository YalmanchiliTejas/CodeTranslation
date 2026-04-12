#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  string s;
  cin >> n >> s >> k;
  char c = s.at(k-1);
  for (char cc : s) {
    if (cc == c) cout << cc;
    else cout << '*';
  }
  cout << endl;
  return 0;
}

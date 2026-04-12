#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  char key = s.at(k - 1);
  for (int i = 0; i < n; i++) {
    cout << (s.at(i) == key ? s.at(i) : '*');
  }
  cout << endl;
  return 0;
}

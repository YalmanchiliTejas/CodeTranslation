#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string S;
  cin >> S;
  set<char> se;
  for (int i = 0; i < 3; i++) {
    se.insert(S[i]);
  }
  cout << (se.size() == 1 ? "No" : "Yes") << endl;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;
  unordered_set<char> C;
  for (char c : S) C.insert(c);
  if (C.size() == 1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}

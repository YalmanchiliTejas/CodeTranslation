#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;

  for (char c: s)
    cout << (c == s[k - 1] ? c : '*');
  cout << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  bool ans = true;
  if (S == "AAA" || S == "BBB") ans = false;
  cout << (ans ? "Yes" : "No") << endl;
}
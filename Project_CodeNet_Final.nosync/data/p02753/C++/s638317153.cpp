#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

const string YES = "Yes";
const string NO = "No";

void solve(string S) {
  bool pred = S.find('A') != S.npos && S.find('B') != S.npos;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  string S;
  cin >> S;
  solve(S);
  return 0;
}

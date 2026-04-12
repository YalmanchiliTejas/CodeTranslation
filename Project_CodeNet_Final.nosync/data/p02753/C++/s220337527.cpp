#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  S.erase(unique(S.begin(), S.end()), S.end());
  cout << ((S.size() == 1) ? "No" : "Yes") << "\n";
}
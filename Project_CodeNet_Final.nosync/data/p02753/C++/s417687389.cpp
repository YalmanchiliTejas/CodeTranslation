#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S; cin >> S;
  if (S[0] == S[1] && S[1] == S[2]) cout << "No" << "\n";
  else cout << "Yes" << "\n";
}
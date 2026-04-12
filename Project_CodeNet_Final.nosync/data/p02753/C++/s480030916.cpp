#include <iostream>
#include <string>

#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  string S;
  cin >> S;

  if (S[0] != S[1] || S[0] != S[2] || S[1] != S[2]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
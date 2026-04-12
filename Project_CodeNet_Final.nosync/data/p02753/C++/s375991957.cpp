#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  if (std::string::npos != S.find("A") && std::string::npos != S.find("B")) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
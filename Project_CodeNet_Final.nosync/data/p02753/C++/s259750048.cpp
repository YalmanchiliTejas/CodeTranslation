#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for(int i = 0; i < S.size(); i++) {
    if(S.at(0) != S.at(i)) {
      cout << "Yes" <<endl;
      break;
    }
    else if(i == S.size() - 1) {
      cout << "No" <<endl;
    }
  }
}

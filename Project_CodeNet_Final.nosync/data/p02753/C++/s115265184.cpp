#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  int cntA = 0, cntB = 0;
  for(int i = 0; i < 3; i++) {
    if(S.at(i) == 'A') {
      cntA++;
    } else {
      cntB++;
    }
  }

  if(cntA == 0 || cntB == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}

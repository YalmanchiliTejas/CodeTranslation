#include <bits/stdc++.h>

using namespace std;

//int cntT[30];
//int cntP[30];

int main() {
  string T, P;
  cin >> T >> P;
  int n = T.size();
  int m = P.size();
  int idx = 0;
  int cntT = 0, cntP = 0;
  bool flag = true;
  for(int i = 0; i < n; i++) {
    if(T[i] == P[idx]) {
      idx++;
    } else if(idx > 0 && T[i] == P[idx-1]) {
      flag = false;
    }
  }
  cout << (flag && idx == m ? "yes" : "no") << endl;
  return 0;
}
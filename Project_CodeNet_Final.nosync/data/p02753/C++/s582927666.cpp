#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int cnt_A = 0, cnt_B = 0;
  for (int i = 0; i < 3; i++) {
    if (S[i] == 'A') cnt_A++;
    if (S[i] == 'B') cnt_B++; 
  }
  if (cnt_A > 0 && cnt_B > 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int a_c = 0, b_c = 0;
  for(int i = 0; i < 3; i++){
    if(S[i] == 'A') a_c++;
    else b_c++;
  }
  if(a_c > 0 && b_c > 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
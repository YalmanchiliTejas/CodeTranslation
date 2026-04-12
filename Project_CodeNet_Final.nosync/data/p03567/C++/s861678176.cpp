#include <bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int flag = 0;
  for(int i = 0; i < S.size() - 1; i++){
    if(S.substr(i, 2) == "AC")flag = 1;
  }
  if(flag == 0)cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}

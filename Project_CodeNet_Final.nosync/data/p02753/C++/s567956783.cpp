#include <bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  char A = S.at(0);
  string B = "No";
  for(int i = 0; i < S.size(); i++){
    if(S.at(i) != A){
      B = "Yes";
      break;
    }
  }
  cout << B << endl;
}
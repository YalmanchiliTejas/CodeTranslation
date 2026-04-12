#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;

  bool ans = true;
  if (S.at(0)=='A' && S.at(1)=='A' && S.at(2)=='A') ans=false;
  if (S.at(0)=='B' && S.at(1)=='B' && S.at(2)=='B') ans=false;
  
  if (ans) {
   cout << "Yes" << endl;
  }
  else {
   cout << "No" << endl;
  }

}
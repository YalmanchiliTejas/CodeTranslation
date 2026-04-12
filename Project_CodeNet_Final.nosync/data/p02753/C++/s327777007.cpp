#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  bool K=false;
  bool L=false;
  for (int X=0; X<S.size(); X++){
    if (S.at(X)=='A'){
      K=true;
    }
    else if (S.at(X)=='B'){
      L=true;
    }
  }
  if (K==true && L==true){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" <<endl;
  }
}
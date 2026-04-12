#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  
  bool a = S.at(0) == S.at(1);
  bool b = S.at(1) == S.at(2);
  bool c = S.at(2) == S.at(0);
  
  if(a && b && c){
    cout << "No" << endl;
  }
  
  else{
    cout << "Yes" << endl;
  }
}
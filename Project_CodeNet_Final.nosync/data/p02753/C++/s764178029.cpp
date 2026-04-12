#include<bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  
  int num=0;
  for ( int i = 0 ; i < 2 ; i++) {
    if (str.at(i) != str.at(i+1) ) {
      num = 1 ; 
      break;
    }
  }

  if ( num == 0  ) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
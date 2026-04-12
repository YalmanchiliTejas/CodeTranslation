#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int count = 0;
  int sum = 0;
  
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == 'A') {
      count++;
    }
    else if (S.at(i) == 'B'){
       sum++;
    }

  }
  if ( count == 3 || sum ==3 ) {
    cout << "No" << endl;
  }
 
  else {
    cout << "Yes" << endl;
  }
   
 }


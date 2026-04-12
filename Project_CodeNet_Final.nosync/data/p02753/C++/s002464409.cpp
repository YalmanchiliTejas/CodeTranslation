#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int counta = 0;
  int countb = 0;
  
  for (int i = 0; i < S.size(); i++) {
  
    if (S.at(i) == 'A') {
      counta++;
    }
    else if (S.at(i) == 'B') {
      countb++;
    }
  }
  
  if (counta == 3 or countb == 3){
   cout << "No" << endl;
  }
  else{
   cout << "Yes" << endl;
  }
}

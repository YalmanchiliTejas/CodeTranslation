#include <bits/stdc++.h>
//#include <cstdlib>
//#include <cmath>

using namespace std;

int main() {
  
  
  string vo_cal = "aeiou";
  
  char c;
  cin >> c;
  
  
  for (int i = 0; i<5 ; i++){
    if (c == vo_cal.at(i)){
      cout << "vowel" << endl;
      break;
    }
    else if ( i == 4 ){
      cout << "consonant" << endl;
    }
    
  }
  
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c ;
 vector <char> boin = {'a' ,'i' ,'u','e','o'};
 for ( int i = 0 ; i < 5 ; i++){
   if ( c == boin.at(i) ){
      cout << "vowel" << endl;
      break;
   }
   if( i == 4 ){
     cout << "consonant" << endl;
   }
  }
}


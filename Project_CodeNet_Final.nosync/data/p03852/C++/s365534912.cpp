#include<bits/stdc++.h>
using namespace std ;

int main () {
  char S ;
  cin >> S ;
  
  vector<char> boin = { 'a' , 'i' , 'u' , 'e' , 'o' } ;
  
  int score ;
  
  for ( int i = 0 ; i < 5 ; i++ ){
    if ( S ==  boin.at(i) ){
      score ++ ;
    }
  }
  
  if ( score == 1 ){
    cout << "vowel" << endl ;
  } else {
    cout << "consonant" << endl ;
  }
}
#include <cstdio>
#include <iostream>

#define rep(i,n) REP(i,0,n)
#define REP(i, a, n) for(int i = a; i < (int)n ; i++)

using namespace std;

char c;

signed main(){
  cin >> c;
  
  switch(c){
  case 'a':
  case 'i':
  case 'u':
  case 'e':
  case 'o':
    cout << "vowel" << endl;
    break;
  default:
    cout << "consonant" << endl;
  }
  
  
}

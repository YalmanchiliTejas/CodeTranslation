#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int  H , W ;
  cin >> H >> W;
  vector <bool> gyou(H,false) , retu(W, false);
  vector <string> s(H) ;
  for ( int i=0 ; i<H ; i++ ){
    cin >> s[i] ;
  }
  for ( int i=0 ; i<H ; i++){
    for (int j= 0 ; j <W ;j++){
      if (s.at(i).at(j) == '#' ) {
        gyou.at(i) = true ;
        retu.at(j) = true ;
      }
    }
  }
    for ( int i=0 ; i<H ; i++){
    for (int j= 0 ; j <W ;j++){
      if ( gyou.at(i) && retu.at(j)) {
      cout << s.at(i).at(j)  ;
      }
    }
      cout << endl;
  }
}
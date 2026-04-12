#include<bits/stdc++.h>
using namespace std ;

int main () {
  string a ;
  cin >> a ;
  
  int pre = 10 ;
  bool x = false , b = false ;
  
  for(int i = 0 ; i < 5 ; i++ ){
    if(a[i] == 'A'){
      x = true ;
      pre = i ;
      break ;
    }
  }
  
  if(a[pre+1] == 'C') b = true ;
  
  if(x&&b) cout << "Yes" << endl ;
  else cout << "No" << endl ;
  
}

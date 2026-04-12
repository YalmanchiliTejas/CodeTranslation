#include<bits/stdc++.h>
using namespace std ;

int main () {
  int N , pre , ans = 1 ;
  cin >> N >> pre ;
  for(int i = 0 ; i < N -1 ; i++ ){
    int a ;
    cin >> a ;
    if(pre<=a){
      ans++ ;
      pre = a ;
    } else {
    }
  }
  cout << ans << endl ;
}
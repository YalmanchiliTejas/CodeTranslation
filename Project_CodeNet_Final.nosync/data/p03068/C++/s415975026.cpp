#include<bits/stdc++.h>
using namespace std ;

int main () {
  int N , K ;
  string S ;
  cin >> N >> S >> K ;
  char a = S[K-1] ;
  for(int i = 0 ; i < N ; i++ ){
    if(S[i]==a) cout << a ;
    else cout << '*' ;
  }
  cout << endl ;
}

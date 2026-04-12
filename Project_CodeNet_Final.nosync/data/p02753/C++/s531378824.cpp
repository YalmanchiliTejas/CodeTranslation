#include <bits/stdc++.h>
using namespace std;

main(){
  string S ;
  cin >> S ;
  if(S[0] == S[1]){
    if(S[0] == S[2]){
      cout << "No" ;
      return 0 ;
    }
  }
  cout << "Yes" ;
  return 0 ;
}
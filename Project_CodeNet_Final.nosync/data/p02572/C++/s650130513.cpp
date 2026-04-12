#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; cin >> N ; 
  vector<int64_t> A(N) ; 
  int64_t ans = 0 ;
  
  for(int i = 0 ; i < N ; i++){
    cin >> A.at(i) ; 
  }
  

  int64_t x = A.at(0)%(1000000007)  ; 
  
  
  for(int i = 1 ; i < N ; i++){
    ans += (A.at(i)*x );
    ans %= (1000000007);
    x += A.at(i) ;
    x %=(1'000'000'007);

  }
  
  cout << ans << endl ;
  
}
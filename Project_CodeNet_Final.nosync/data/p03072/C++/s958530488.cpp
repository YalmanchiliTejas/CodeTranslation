#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
 
int main() {
  
  int N  ;
  cin >> N ;
  int max = 0 ;
  int ans = 0 ; 
  vector<int> A(N) ; 
  rep(i,N) cin >> A.at(i);
  rep(i,N){
    if( max <= A.at(i) ) {
    ans++;
    max = A.at(i) ;  
    }
  
  }
  cout << ans << endl;
}

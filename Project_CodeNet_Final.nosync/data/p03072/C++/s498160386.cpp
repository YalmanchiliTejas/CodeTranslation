#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,h;
  int m=0,ans=0;
  
  cin >> n;
  
  for(int i=0; i<n; i++){
    cin >> h;
    if( m <= h ) ans ++;
    m = max( m , h );
  }
  
  cout << ans << endl;
  
  return 0;
}
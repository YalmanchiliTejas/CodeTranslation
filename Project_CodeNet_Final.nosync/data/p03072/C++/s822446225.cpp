#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, las = -1 , ans = 0;
  cin >> N;
  
  
  for (int i = 0; i < N ; i++){
    
    int h;
    cin >> h;
    
    if (las < 0){
      ans ++;
      las = h;
    }
    else if ( h >= las ){
       ans++;
       las = h;
    }
  }
  
  cout << ans << endl;
}

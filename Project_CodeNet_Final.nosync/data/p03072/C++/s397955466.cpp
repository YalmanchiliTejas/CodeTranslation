#include <iostream>
using namespace std;

int main(){
  int n, h, ans, max;
  cin >> n;
  max = 0;
  ans = 0;
  for ( int i = 0; i < n; i++ ) {
    cin >> h;
    if ( h >= max ) {
      max = h;
      ans ++;
    }
  }
  
  cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,z;
  cin >> x >> y >> z;
  int ans=0;
  for ( int i=0; i<=x; i++ ) {
    if ( y*i+(i+1)*z <= x ) {
      ans=i;
    } else {
	  break;
    }
  }
  cout << ans << '\n';
  return 0; 
}
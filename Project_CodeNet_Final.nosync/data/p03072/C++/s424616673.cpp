#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  int ans = 0;
  int check = 0;
  for ( int i = 0; i < N; i++) {
    int H;
    cin >> H;
    if ( check <= H ) {
      check = H;
      ans++;
    }
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n, l, r;
  while ( cin >> n >> l >> r, n ) {
    vector<int> A(n);
    for ( int i = 0; i < n; i++ ) {
      cin >> A[i];      
    }

    int ans = 0;
    for ( int i = l; i <= r; i++ ) {
      int j;
      for ( j = 0; j < n; j++ ) {
	if ( i%A[j] == 0 ) break;	
      }
      if ( j%2 == 0 ) ans++;      
    }

    cout << ans << endl;    
  }
  
  return 0;
}


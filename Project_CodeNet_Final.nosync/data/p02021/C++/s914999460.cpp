#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;

  vector<int> A(N);
  for ( int i = 0; i < N; i++ ) {
    cin >> A[i];
  }

  for ( int i = 100; i >= 0; i-- ) {
    int sum = 0;
    for ( int j = 0; j < N; j++ ) {
      sum += A[j];
      if ( sum < i ) break;
      sum -= i;      
      if ( j == N-1 ) {
	cout << i << endl;
	return 0;
      }
    }
  }  
  
  return 0;
}


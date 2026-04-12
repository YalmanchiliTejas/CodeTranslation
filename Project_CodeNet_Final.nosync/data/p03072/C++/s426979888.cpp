#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for ( int i = 0 ; i < n ; i++ )

int main() {
  int N;
  cin >> N;
  vector<int> M(N,0);
  int high = 0;
  int ans = 0;
  REP(i,N) {
    cin >> M[i];
    if (high <= M[i] ) {
      high = M[i];
      ans++;
    }
  }
  cout << ans << endl;
}
      
    
  
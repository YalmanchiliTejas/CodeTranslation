#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, X;
int P[51];
int L[51];

int dfs(int n, int x) {
  // cout << n << " " << x << endl;
  if ( L[n] <= x ) return P[n];
  if ( n < 0 || x == 0 ) return 0;  

  int add = (x >= (L[n]+1)/2);
  if ( x > (L[n]+1)/2 ) return dfs(n-1, L[n-1]) + dfs(n-1, x-(L[n]+1)/2) + add;  
  else return dfs(n-1, x-1) + add;
}

signed main() {
  cin >> N >> X;

  P[0] = 1LL;
  L[0] = 1LL;  
  for ( int i = 1; i < 51; i++ ) {
    P[i] = 2LL*P[i-1]+1LL;
    L[i] = 2LL*L[i-1]+3LL;    
  }

  /*for ( int i = 0; i < 4; i++ ) {
    cout << P[i] << " " << L[i] << endl;
    }*/

  cout << dfs(N, X) << endl;

  return 0;
}

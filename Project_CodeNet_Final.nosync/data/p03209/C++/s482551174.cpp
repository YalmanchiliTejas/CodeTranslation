#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

int P[55];
int T[55];

int solve( int n, int x ){
  if( n == 0 ){
    if( x == 1 ) return 1;
    else return 0;
  }else if( x == 1 ) return 0;
  if( T[n] == x ) return P[n];
  else if(T[n]/2+1 <= x ) return P[n-1]+1 + solve(n-1, x-T[n]/2-1);
  else return solve(n-1, x-1);
}

signed main(){
  int N, X;
  cin >> N >> X;
  T[0] = 1;
  P[0] = 1;
  for( int i = 1; i <= N; i++ ){
    T[i] = 2*T[i-1]+3;
    P[i] = 2*P[i-1]+1;
  }

  cout << solve(N, X) << endl;

}

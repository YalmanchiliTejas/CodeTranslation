#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A[i];
  vector<int> R(N+1, 0);
  for( int i = 0; i < N; i++ ) R[i+1] = (A[i]+R[i]);
  int ans = 0;
  for( int i = 0; i < N; i++ ){
    int b = (R[N]-R[i+1]);
    b %= MOD;
    int tasu = A[i]*b;
    tasu %= MOD;
    ans += tasu;
    ans %= MOD;
  }
  cout << ans%MOD << endl;

}

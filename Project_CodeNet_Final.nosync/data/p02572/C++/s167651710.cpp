#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 1000000007
using ll = long long;
using vi = vector<int>;

int main()
{
  int N; cin >> N;
  vi A(N);
  REP( i, N ) {
    cin >> A[i];
  }
  
  ll ans = 0, tmp = A[N-1];
  FOR( i, 1, N ) {
    int n = N-1-i;
    ans += tmp * A[n];
    tmp += A[n];
    ans %= MOD; tmp %= MOD;
    
  }
  cout << ans;
}
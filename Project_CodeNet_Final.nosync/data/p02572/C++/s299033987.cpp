#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(long long i=0; i<n; i++)

long long MOD = 1000000007;

int main(){
  long long N;
  cin >> N;
  long long A[N];
  rep(i, N)
    cin >> A[i];
  //

  long long sum[N];
  rep(i, N)
    sum[i] = 0;

  sum[0] = A[0];
  rep(i, N-1){
    sum[i+1] = (sum[i]+A[i+1]);
  }

  long long ans = 0;
  rep(i, N-1){
    ans = (ans + (A[i]*( (sum[N-1]-sum[i])%MOD) )%MOD) % MOD;
  }

  cout << ans << endl;
  
  
  return 0;
}

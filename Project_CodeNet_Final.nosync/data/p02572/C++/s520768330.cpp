#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000*1000*1000+7;
int main(){

  int N; cin >> N;
  vector<long long> v(N);
  for(int i=0; i<N; i++) cin >> v[i];

  vector<long long> cum(N+1,0);
  for(int i=0; i<N; i++) cum[i+1] = (cum[i] + v[i]) % MOD;

  long long ans = 0;
  for(int i=0; i<N-1; i++){
    ans += v[i] * (cum[N]-cum[i+1] + MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
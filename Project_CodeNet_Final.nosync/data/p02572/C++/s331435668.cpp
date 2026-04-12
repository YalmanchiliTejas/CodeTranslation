#include<bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;

int main(){
  int N;
  cin >> N;
  vector<int64_t> vec(N);
  vector<int64_t> sum(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  
  for(int i=1; i<N; i++){
    sum[i] = sum[i-1] + vec[i-1];
  }
  
  int64_t ans = 0;
  
  for(int i=0; i<N; i++){
    ans += (sum[i] % MOD) * vec[i];
    ans %= MOD;
  }
  
  cout << ans << endl;
}
  
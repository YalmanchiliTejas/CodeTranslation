#include <bits/stdc++.h>
using namespace std;
int main() {
  int N; cin >> N;
  int MOD = 1000000007;
  vector<int> A(N);
  long long sum=0;
  for(int i=0; i<N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
    sum %= MOD;
  }
  
  long long ans=0;
  for(int i=0; i<N; i++) {
    sum -= A.at(i);
    if(sum <0) sum += MOD;
    
    ans += A.at(i) * sum;
    ans %= MOD;
  }
    cout << ans << endl;
}
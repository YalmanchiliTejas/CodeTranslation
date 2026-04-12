/* C - Sum of product of pairs */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, mod = 1000000007;
  long long sum = 0, ans = 0;
  cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
    sum += A.at(i);
    sum %= mod;
  }
  for(int i = 0; i < N; i++){
    sum -= A.at(i);
    if(sum < 0) sum += mod;
    ans += A.at(i) * sum;
    ans %= mod;
  }
  cout << ans << endl;
}

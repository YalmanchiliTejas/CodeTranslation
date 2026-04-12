#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0;
  cin >> N;
  vector<ll>A(N);
  ll sum = 0;
  rep(i,N){
    cin >> A[i];
    sum += A[i];
    sum %= 1000000007;
  }
  ll ans = 0;
  rep(i,N-1){
    if(sum - A[i] >= 0){
      sum = sum - A[i];
      ans += (A[i] * sum) % 1000000007;
    }
    else{
      sum = sum - A[i] + 1000000007;
      ans += (A[i] * sum) % 1000000007;   
    }
  }
  cout << ans % 1000000007;
}
    
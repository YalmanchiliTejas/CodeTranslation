#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,i, mod=1000000007;
  long long ans=0, sum=0;
  cin>>N;
  vector<long long> A(N);
  for (i=0;i<N;i++) {
    cin>>A[i];
    sum += A[i];
  }
  for (i=0;i<=N-2;i++) {
    sum -= A[i];
    ans += A[i] * (sum % mod);
    ans %= mod;
  }
  cout<<ans<<endl;
  return 0;
}

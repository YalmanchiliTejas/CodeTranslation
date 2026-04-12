#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<long long> S(N+1,0);
  int mod = 1000000007;
  for(int i=0; i<N; i++){
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }
  long long ans = 0;
  
  for(int i=0; i<N; i++){
    long long sum = (S[N] - S[i+1]) % mod;
    ans += A[i] * sum;
    ans %= mod;
  }
  cout << ans << endl;
}
    
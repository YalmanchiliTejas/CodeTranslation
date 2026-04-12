#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  
  vector<int> A(N);
  for(int i=0;i<N;i++) cin >> A[i];
  
  long long ans=0;
  long long sum=0;
  long long kari=0;
  
  for(int i=0;i<N;i++) sum += A[i];
  
  for(int i=0;i<N;i++){
    sum -= A[i];
    kari = sum % 1000000007;
    ans += A[i] * kari;
    ans %= 1000000007;
  }
  
  cout << ans << endl;
}

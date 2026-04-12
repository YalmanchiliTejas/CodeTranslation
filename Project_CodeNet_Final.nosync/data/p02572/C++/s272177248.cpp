#include<bits/stdc++.h>
using namespace std;


int main(){
  uint64_t N;
  cin >> N;

  vector<uint64_t> A(N,0), B(N,0);

  for(uint64_t i=0;i<N;i++){
    cin >> A[i];
  }
  

  for(uint64_t i=0; i <= N-2; i++){
    int j = N-2 - i;
    B[j] = (B[j+1] + A[j+1]) % 1000000007; 
  }

  uint64_t sum=0;
  
  for(uint64_t i=0;i<=N-2;i++){
    sum = (sum + (( A[i] * B[i]) % 1000000007) )% 1000000007;
  }

  cout << sum << endl;

}

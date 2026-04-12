#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N, K;
  cin >> N >> K;
  int64_t ans = 0;
  if(K == 0){
    ans = N*N;
  }
  else{
   for(int64_t i=K+1; i<=N; i++){
    ans += N/i *(i-K);
    if(N %i >= K){
    ans += N%i -(K-1);
    }
   }
  }
  cout << ans << endl;
}
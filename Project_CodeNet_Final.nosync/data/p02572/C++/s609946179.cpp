#include<iostream>
using namespace std;

const long long MOD=1000000007;

int main(void){
  int N;
  long A[200001];
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  
  long long sum=0;
  long long dsum=0;
  for (int i=0; i<N; i++){
    sum += A[i];
    dsum += A[i] * A[i];
    sum = sum % MOD;
    dsum = dsum % MOD;
  }
  
  long long all = sum*sum-dsum;
  long long ans;
  
  if (all % 2 == 0){
    ans = all / 2;
  }
  else{
    ans = (all + MOD)/2;
  }
  ans = ans % MOD;
  
  cout << ans << endl;
  
  return 0;
}
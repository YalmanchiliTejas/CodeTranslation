#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  const long long M = 1000000007;
  vector<long long> A(N);
  vector<long long> S(N+1);
  for(int i = 0; i < N; i++){
    cin >> A[i];
    A[i] %= M;
    S[i+1] = (S[i]+A[i])%M;
  }
  long long sum = 0;
  for(int i = 0; i < N-1; i++){
    if(S[N] < S[i+1]){
      sum = sum+(A[i]*(M+S[N]-S[i+1]))%M;
    }else{
      sum = sum+(A[i]*(S[N]-S[i+1]))%M;
    }
  }
  cout << sum%M << endl;
}

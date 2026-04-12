#include <bits/stdc++.h>
using namespace std;;

int main(void){
  long long N;
  int X, M;
  cin >> N >> X >> M;
  vector<long long> A, Asum;
  A.push_back(X);
  Asum.push_back(X);
  int lps;
  int lpl;
  for(int i = 0; i < N-1; i++){
    A.push_back(A[i]*A[i]%M);
    Asum.push_back((Asum[i]+A[i+1]));
    for(int j = 0; j < A.size()-1; j++){
      if(A[i+1] == A[j]){
        lps = j;
        lpl = i-j+1;
        goto lpfind;
      }
    }
  }
  lpfind:
  
  if(A.size() == N){
    cout << Asum[N-1] << endl;
    return 0;
  }
  
  long long ans;
  long long lpc = (N - lps)/lpl;
  
  if(lps == 0){
    ans = Asum[lpl-1]*lpc;
  }
  else{
    ans = Asum[lps-1];
    ans += (Asum[lps+lpl-1] - Asum[lps -1])*lpc;
  }
  
  int residual = 0;
  for(long long i = lps + lpl*lpc; i < N; i++){
    ans += A[lps+residual];
    residual++;
  }
  
  cout << ans << endl;
}
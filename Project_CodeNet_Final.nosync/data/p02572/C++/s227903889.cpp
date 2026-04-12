#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N;
  scanf("%d", &N);
  
  vector<long long> v(N);
  for(int i=0;i<N;i++){
      scanf("%d", &v[i]);
  }

  long long S = 0;  
  long long MOD = pow(10,9)+7;
  
  vector<long long> CUMSUM(N);
  CUMSUM[N-1] = v[N-1];
  for (int i=N-2;i>=0;i--){
    CUMSUM[i] = (v[i] + CUMSUM[i+1])%MOD;
  }

  for (int i=0;i<N-1;i++){
    S+=v[i]*CUMSUM[i+1]%MOD;
  }
  
  S%=MOD;

  printf("%d\n", S);  
  
  return 0;
}

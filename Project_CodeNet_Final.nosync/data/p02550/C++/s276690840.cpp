#include<bits/stdc++.h>
using namespace std;

int main(){
  long int N, X, M;
  cin >> N >> X >> M;
  vector<long int> B(M+1);
  vector<long int> C(M);
  long int ans = 0;
  int f = 0;
  for (int i = 1; i <= N; i++){
  	B[i] = B[i-1] + X;
    if (C[X] != 0){
      ans += ((N-C[X]+1) / (i-C[X])) * (B[i-1] - B[C[X]-1]);
      ans += B[C[X] + (N-C[X]+1) % (i-C[X]) - 1];
      f = 1;
      break;
    }
    else{
    	C[X] = i;
    }
    X = X * X % M;
  }
  if (f == 1)
    cout << ans << endl;
  else
    cout << B[N] << endl;
  return 0;
}
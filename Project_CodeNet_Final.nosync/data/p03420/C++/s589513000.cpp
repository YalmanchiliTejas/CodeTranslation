#include <iostream>

using namespace std;

int main(){
  long long N,K,i,j,n=0;
  cin >> N >> K;
  if (K==0) {
    cout << (N*N);
    return 0;
  }
  for (j=K+1;j<=N;j++) {
    if (N%j>=K-1) {
      n+=(N/j) * (j-K) + N%j -(K-1);
    } else {
      n+=(N/j) * (j-K);
    }
  }
  cout << n;
  return 0;
}

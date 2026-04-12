#include <iostream>
#include <vector>
using namespace std;

vector<long long> A(51);
vector<long long> P(51);

long long func(long long N, long long X) {
  if(N==0) {
    return 1;
  }
  
  if(X==1) {
    return 0;
  
  } else if(X>=2 && X<=1+A[N-1]) {
    return func(N-1, X-1);
  
  } else if (X==2+A[N-1]) {
    return P[N-1] + 1;
    
  } else if (X>=3+A[N-1] && X<=2+2*A[N-1]) {
    return func(N-1, X-2-A[N-1]) + 1 + P[N-1];
  
  } else if(X==A[N]){
    return P[N];
  }
}

int main() {
  long long N, X;
  cin >> N >> X;
  
  A[0] = 1;
  P[0] = 1;
  for(int i=1; i<=50; i++) {
    A[i] = A[i-1]*2+3;
    P[i] = P[i-1]*2+1;
  }
  
  cout << func(N, X) << endl;
  return 0;
}
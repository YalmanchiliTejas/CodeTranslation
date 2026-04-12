#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,answer=0,i;
  cin >> N;
  vector<long> A(N);
  for (i=0;i<N;i++){
    cin >> A[i];
  }
  long long B=0,C;
  for(i=1;i<N;i++){
    B+=A[i];
  }
  C=B%1000000007;
  answer+=C*A[0];
  answer=answer%1000000007;
  
  for (i=1;i<N-1;i++){
      B-=A[i];
    C=B%1000000007;
    answer+=C*A[i];
    answer=answer%1000000007;
  }
  
  cout<<answer;
  }
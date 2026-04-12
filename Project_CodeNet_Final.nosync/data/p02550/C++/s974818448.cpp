#include <bits/stdc++.h>
using namespace std;
  
int main() {
  long long N,X,M;
  cin >> N >> X >> M;
  
  if (M == 1){
    cout << 0 << endl;
    return 0;
  }
  
  long long sum1 = 0;
  long long sum2 = 0;
  vector<long long>L(M);
  vector<long long>count(M,0);
  L.at(0) = X;
  count.at(X)++;
  long long A = -1;
  long long B = -1;
  long long Y = -1;
  
  if (N == 1){
    cout << X << endl;
    return 0;
  }
  
  for (int i = 1; i < M; i++) {
    L.at(i) = (L.at(i-1)*L.at(i-1)) % M;
    count.at(L.at(i))++;
    if (count.at(L.at(i)) > 1){
      A = i+1;
      Y = L.at(i);
      break;
    }
  }
  
  long long ans = 0;
  if (A == -1){
    for (int i = 0; i < N; i++) {
      ans += L.at(i);
    }
    cout << ans << endl;
    return 0;
  }
      
  
  long long judge = 0;
  for (int i = 0; i < A; i++) {
    if (L.at(i) == Y){
      judge++;
      if (judge == 1){
        B = i+1;
      }
    }
    if (judge == 0){
      sum1 += L.at(i);
    }
    else if (judge == 1){
      sum2 += L.at(i);
    }
  }
  
  if (N < A){
    for (int i = 0; i < N; i++) {
      ans += L.at(i);
    }
  }
  else {
    long long C = (N-B+1)/(A-B);
    long long D = (N-B+1)%(A-B);
    for (int i = B-1; i < B+D-1; i++) {
      ans += L.at(i);
    }
    ans += sum1 + C*sum2;
  }
  cout << ans << endl;
}
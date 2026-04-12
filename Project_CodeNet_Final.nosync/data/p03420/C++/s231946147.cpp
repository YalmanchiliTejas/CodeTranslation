#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  LL N, K;
  cin >> N >> K;
  LL sum=0;
  if(K==0) {
    sum = N*N;
  } else {
    for(LL i=K; i<=N; ++i) {
      sum += (N/i)*(i-K);
      sum += max(0ll, (N%i) - K + 1);
    }
  }
  cout << sum << endl;
}

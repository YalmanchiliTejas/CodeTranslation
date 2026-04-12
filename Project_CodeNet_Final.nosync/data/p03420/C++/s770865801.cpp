#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  ll N,K; cin>>N>>K;
  ll sum = 0;

  if (K == 0) {
    cout << N * N << "\n";
    return 0;
  }

  for (ll b = K + 1; b <= N; b++) {
    sum += (b - K) * (N / b);
    int rem = N % b;
    if(rem >= K) {
      sum += (rem - K + 1);
    }
  }
  cout << sum << "\n";
  return 0;
}
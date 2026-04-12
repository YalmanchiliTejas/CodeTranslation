#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long MOD = 1000000007;

void solve(long long N, std::vector<long long> A){
  vector<ll> sA(A.size());
  partial_sum(A.begin(), A.end(), sA.begin());
  for (auto & sai : sA) {
    sai = sai % MOD;
  }
  ll rv = 0;
  for (size_t i = 0; i < sA.size() -1; ++i) {
    ll p = (sA[i] * A[i+1]) % MOD;
    rv = (rv + p) % MOD;
  }
  cout << rv << endl;
}

int main() {
  long long N;
  scanf("%lld",&N);
  std::vector<long long> A(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
  }
  solve(N, std::move(A));
  return 0;
}

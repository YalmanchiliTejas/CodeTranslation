#include <bits/stdc++.h>
using namespace std;

long long N, K;
long long H[100];
vector<long long> L;
long long P[60];
long long D[101][101];
#define MOD 1000000007LL
long long R;

long long pow(long long x) {
  long long r = 1;
  for(long long b = 0; b < 60; ++b) {
    if((1LL << b) & x) (r *= P[b]) %= MOD;
  }
  return r;
}
int main() {
  P[0] = 2LL;
  for(long long i = 1; i < 60; ++i) {
    P[i] = P[i - 1] * P[i - 1] % MOD;
  }
  cin >> N;
  L.push_back(0);
  for(long long i = 0; i < N; ++i) {
    cin >> H[i]; L.push_back(H[i]);
  }
  sort(L.begin(), L.end());
  L.erase(unique(L.begin(), L.end()), L.end());
  K = L.size();
  /*for(long long k = 0; k < K; ++k) {
    cout << "L[" << k << "] : " << L[k] << endl;
  }*/
  long long prev_l = 0; D[0][0] = 1;
  for(long long i = 0; i < N; ++i) {
    long long l = lower_bound(L.begin(), L.end(), H[i]) - L.begin();
    /*cout << "i=" << i
      << " l=" << l << " prev_l=" << prev_l << endl;*/
    if(prev_l >= l) {
      (D[i + 1][0] += 2 * D[i][0] % MOD) %= MOD;
      for(long long k = 1; k <= l; ++k) {
        (D[i + 1][k] += D[i][k]) %= MOD;
      }
      for(long long k = l + 1; k <= prev_l; ++k) {
        (D[i + 1][0] += 2 * D[i][k] % MOD) %= MOD;
      }
    } else {
      (D[i + 1][0] += 2 * D[i][0] % MOD) %= MOD;
      for(long long k = prev_l + 1; k <= l; ++k) {
        (D[i + 1][k] +=
          2
          * (pow(L[k] - L[k - 1] - (k - 1 == 0 ? 1 : 0)) + MOD - 1) % MOD
          * pow(L[l] - L[k]) % MOD
          * D[i][0]) %= MOD;
      }
      long long C = pow(L[l] - L[prev_l]);
      for(long long k = 1; k <= prev_l; ++k) {
        (D[i + 1][k] += C * D[i][k] % MOD) %= MOD;
      }
    }
    /*for(long long k = 0; k <= l; ++k) {
      cout << "  " << "D[][" << k << "]="
        << D[i + 1][k] << endl;
    }*/
    prev_l = l;
  }
  for(long long k = 0; k < K; ++k) {
    (R += D[N][k]) %= MOD;
  }
  cout << R << endl;
  return 0;
}

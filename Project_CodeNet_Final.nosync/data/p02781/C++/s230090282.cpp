#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long comb(int n, int k) {
  if (n < k || k < 0) return 0;
  long long ans = 1;
  rep(i, k) {
    ans *= n;
    n--;
  }
  rep(i, k) {
    ans /= i + 1;
  }
  return ans;
}

long long calc(string S, int N, int K) {
  if (K > N) return 0;
  if (K == 0) return 1;
  if (S[0] - '0' == 0) return calc(S.substr(1), N - 1, K);
  long long ans = 0;
  ans += comb(N - 1, K) * pow(9, K);

  if (S[0] - '0' > 1) {
    ans += (S[0] - '0' - 1) * comb(N - 1, K - 1) * pow(9, K - 1);
  }
  ans += calc(S.substr(1), N - 1, K - 1);

  return ans;
}

int main(){
  string S; cin >> S;
  int K; cin >> K;
  int N = S.size();

  cout << calc(S, N, K) << endl;
}
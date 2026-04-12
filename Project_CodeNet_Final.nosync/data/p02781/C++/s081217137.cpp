#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int ncK(int N, int K) {
  if (N < K) return 0;
  if (N == 0) return 1;
  int res = 1;
  for (int i = 0; i < K; i++) {
    res *= N - i;
    res /= i + 1;
  }
  return res;
}
int dfs(string &S, int i, int K) {
  int n = S.size();
  int r = n - i;
  if (K < 0 || K > r) {
    return 0;
  } else if (K == 0) {
    return 1;
  }
  int d = S[i] - '0';
  int res = 0;
  if (d == 0) {
    return dfs(S, i + 1, K);
  } else {
    res += (d - 1) * pow(9, K -1) * ncK(r - 1, K - 1);
    res += ncK(r - 1, K) * pow(9, K);
    
    res += dfs(S, i + 1, K - 1);
  }
  return res;
}

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = S.size();
  int res = 0;
  cout << dfs(S, 0, K) << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long M) {
  // solver code
  string ans = N == M ? YES : NO;

  cout << ans << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  solve(N, M);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(long long N) {
    cout << (N*800) - ((N/15) * 200) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long N;
  scanf("%lld", &N);
  solve(N);
  return 0;
}

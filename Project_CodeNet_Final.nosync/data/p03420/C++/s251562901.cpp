#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  if (K == 0) {
    cout << N*N << endl;
    return 0;
  }
  long ans = 0;
  for (long b=1; b<=N; b++) {
    long bk = max(0L, b-K);
    ans += bk*(N/b);
    if (N%b > 0) {
      ans += max(0L, N%b-K+1);
    }
  }
  cout << ans << endl;
}
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  long long ans = 0;
  for(int i = 0; i < N-1; ++i) {
    ans += 2LL*min(1LL*i+1LL, N-1LL-i) * (A[i+1]-A[i]);
  }

  if(N % 2 == 0) ans -= (A[N/2]-A[N/2-1]);
  else {
    ans -= min(A[N/2]-A[N/2-1], A[N/2+1]-A[N/2]);
  }
  cout << ans << endl;
  return 0;
}

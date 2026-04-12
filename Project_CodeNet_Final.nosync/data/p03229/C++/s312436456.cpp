#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A,A+N);
  ll msum = 0;
  ll asum = 0;
  for (int i = 0; i < N; i++) {
    if (i < N / 2){
      msum += A[i];
    }
    else {
      asum += A[i];
    }
  }
  ll ans = 0;
  if (N % 2 == 1) {
    if (A[N/2] - A[N/2 - 1] > A[N/2 + 1] - A[N/2]) {
      ans = ((asum - msum) * 2) - A[N/2] - A[N/2 + 1];
    }
    else {
      msum += A[N/2];
      asum -= A[N/2];
      ans = (asum - msum) * 2 + A[N/2] + A[N/2 - 1];
    }
  }
  else {
    ans = (asum * 2) - (msum * 2) - A[N/2] + A[N/2 - 1];
  }
  cout << ans << endl;
  return 0;
}
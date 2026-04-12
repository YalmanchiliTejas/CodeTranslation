#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end(), greater<long long>());
  if (N % 2 == 0) {
    long long ans = 0;
    for (int i = 0; i < N/2 - 1; i++) ans += 2 * A.at(i);
    ans += A.at(N/2 - 1);
    ans -= A.at(N/2);
    for (int i = N/2 + 1; i < N; i++) ans -= 2 * A.at(i);
    cout << ans << endl;
  }
  else {
    long long ans1 = 0;
    for (int i = 0; i < N/2 - 1; i++) ans1 += 2 * A.at(i);
    ans1 += A.at(N/2 - 1) + A.at(N/2);
    for (int i = N/2 + 1; i < N; i++) ans1 -= 2 * A.at(i);
    long long ans2 = 0;
    for (int i = 0; i < N/2; i++) ans2 += 2 * A.at(i);
    ans2 -= A.at(N/2) + A.at(N/2 + 1);
    for (int i = N/2 + 2; i < N; i++) ans2 -= 2 * A.at(i);
    cout << max(ans1, ans2) << endl;
  }
}
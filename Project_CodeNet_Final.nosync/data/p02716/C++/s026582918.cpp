#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  ll odd[(N/2) + 1];
  ll even[((N+1)/2) + 1];
  odd[0] = 0;
  even[0] = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      even[(i/2) + 1] = even[(i/2)] + A[i];
    } else {
      odd[(i/2) + 1] = odd[(i/2)] + A[i];
    }
  }
  ll ans = -1;
  if (N % 2 == 1) {
    ans = odd[N/2];
    ll min_even = 99999999999;
    ll R[((N-1)/2) + 1];
    ll max_D[((N-1)/2) + 1];
    R[((N-1)/2)] = 0;
    max_D[((N-1)/2)] = 0;
    int cnt = 1;
    for (int i = N-2; i >= 1; i-=2) {
      R[((N-1)/2) - cnt] = A[i+1] - A[i] + R[((N-1)/2) - cnt + 1];
      max_D[((N-1)/2) - cnt] = max(max_D[((N-1)/2) - cnt + 1],R[((N-1)/2) - cnt]);
      cnt++;
    }
    for (int i = 0; i < N; i++) {
      if (i % 2 == 0) {
        min_even = min(min_even,A[i]);
      }
    }
    ans = max(ans,even[(N+1)/2] - min_even);
    for (int i = 1; i <= (N/2) - 1; i++) {
      ans = max({ans,even[i] + odd[N/2] - odd[i] + max_D[i],even[i] + odd[N/2] - odd[i]});
    }
    for (int i = 1; i <= (N/2) - 1; i++) {
      ans = max(ans,odd[i] + even[(N+1)/2] - even[i+1]);
    }
    cout << ans << endl;
  } else {
    ans = max(odd[N/2],even[N/2]);
    for (int i = 1; i <= (N/2) - 1; i++) {
      ll res1 = even[i] + odd[N/2] - odd[i];
      ans = max(ans,res1);
    }
    cout << ans << endl;
  }
  return 0;
}
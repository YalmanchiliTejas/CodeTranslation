#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll R[N+1];
  R[0] = 0;
  for (int i = 0; i < N; i++) {
    R[i+1] = R[i] + A[i];
    R[i+1] %= Mod;
  }
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    ll res = A[i] * R[i];
    res %= Mod;
    ans += res;
    ans %= Mod;
  }
  cout << ans << endl;
  return 0;
}
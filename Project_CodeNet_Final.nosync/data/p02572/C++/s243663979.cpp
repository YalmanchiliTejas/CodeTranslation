#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] %= INF;
    sum += A[i];
    sum %= INF;
  }

  ll ans = 0;
  for (int i = N - 1; i > 0; i--) {
    sum -= A[i];
    sum %= INF;
    if (sum < 0) ans += INF;
    ll temp = sum * A[i];
    temp %= INF;
    ans += temp;
    ans %= INF;
  }
  cout << ans << endl;
  return 0;
}
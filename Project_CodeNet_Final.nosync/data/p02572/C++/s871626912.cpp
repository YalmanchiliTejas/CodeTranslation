#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

const ll MOD = 1e9 + 7;

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  vector<ll> A(N);
  for (auto &&a : A) cin >> a;
  ll sm = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    ans = (ans + sm * A[i] % MOD) % MOD;
    sm = (sm + A[i]) % MOD;
  }
  cout << ans << nl;
  return 0;
}

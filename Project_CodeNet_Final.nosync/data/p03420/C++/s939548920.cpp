#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll N, K;
  cin >> N >> K;

  ll ans = 0;
  REP(k, K, N) {
    REP(t, 0, N + 1) if(!(k == 0 && t == 0)) {
      ll s = t == 0 ? N - k : (N - k) / t - k;
      if(s <= 0) break;
      ans += s;
    }
  }
  cout << ans << endl;
}

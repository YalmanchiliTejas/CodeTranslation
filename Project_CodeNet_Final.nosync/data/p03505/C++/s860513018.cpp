#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll K, A, B;

int main(void) {
  cin >> K >> A >> B;

  if(K <= A) cout << 1 << endl;
  else if(A - B <= 0) cout << -1 << endl;
  else {
    ll ans = (K - A) / (A - B) * 2 + 1;
    if((ans / 2 + 1) * A - ans / 2 * B >= K) cout << ans << endl;
    else cout << ans + 2 << endl;
  }
}

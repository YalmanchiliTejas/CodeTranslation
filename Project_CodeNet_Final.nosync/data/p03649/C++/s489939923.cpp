#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, A[50];

bool ok(ll k) {
  ll sum = 0;
  REP(i, 0, N) if(A[i] + k >= N) sum += (A[i] + k - N) / (N + 1) + 1;
  return sum <= k;
}

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> A[i];

  bool f = true;
  REP(i, 0, N) f = f && (A[i] < N);
  if(!f) {
    ll l = 0, h = (1LL << 60);
    while(l + 100000 < h) {
      ll m = (l + h) / 2;
      if(ok(m)) h = m;
      else l = m;
    }
    ll ans;
    REP(i, l, h + 1) {
      if(ok(i)) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}

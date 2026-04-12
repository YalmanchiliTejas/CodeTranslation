#include <iostream>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, A[50];

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> A[i];

  ll ans = 0;
  while(1) {
    bool f = true;
    REP(i, 0, N) f = f && (A[i] < N);
    if(f) break;
    REP(i, 0, N) {
      ll x = A[i] / N;
      A[i] -= x * N;
      REP(j, 0, N) if(i != j) A[j] += x;
      ans += x;
    }
  }
  cout << ans << endl;
}

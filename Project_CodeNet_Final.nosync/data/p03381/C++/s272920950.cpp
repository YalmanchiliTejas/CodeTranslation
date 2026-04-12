#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void) {
  ll N;
  cin >> N;
  vector<pll> A(N);
  REP(i, 0, N) {
    cin >> A[i].first;
    A[i].second = i;
  }

  sort(A.begin(), A.end());

  vector<ll> ans(N);
  REP(i, 0, N) {
    if(i < N / 2) ans[A[i].second] = A[N / 2].first;
    else ans[A[i].second] = A[N / 2 - 1].first;
  }
  REP(i, 0, N) cout << ans[i] << endl;
}

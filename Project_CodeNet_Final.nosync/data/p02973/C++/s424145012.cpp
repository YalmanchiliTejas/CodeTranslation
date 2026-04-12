#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

bool ok(ll N, vi &A, ll k) {
  multiset<ll, greater<ll>> s;
  for (ll i = 0; i < k; i++) s.insert(-1);
  for (ll i = 0; i < N; i++) {
    if (s.upper_bound(A[i]) == s.end()) {
      return false;
    }
    auto j = s.upper_bound(A[i]);
    s.erase(j);
    s.insert(A[i]);
  }
  return true;
}

int main() {
  ll N;
  cin >> N;
  vi A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];

  ll l = 0, r = N;
  while (r - l > 1) {
    ll k = (r + l) / 2;

    if (ok(N, A, k)) {
      r = k;
    } else {
      l = k;
    }
  }

  cout << r << endl;
}

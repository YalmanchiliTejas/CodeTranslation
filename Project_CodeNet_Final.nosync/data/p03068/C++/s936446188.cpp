#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define is(a, b) a == b
#define sz(v) ll(v.size())


void solve(ll N, string S, ll K){
    char target = S[K-1];
    rep(i, N) {
        if (target != S[i]) {
            S[i] = '*';
        }
    }
    cout << S << endl;
}

int main() {
  ll N;
    scanf("%lld",&N);
    string S;
    cin >> S;
    ll K;
    scanf("%lld",&K);
  solve(N, S, K);
  return 0;
}

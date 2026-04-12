#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define is(a, b) a == b
#define sz(v) ll(v.size())


void solve(ll N, vector<ll> a){
    ll dp[N+1][N+1];
    fill(dp[0], dp[N], 0);
    for(int l = N-1; l >= 0; l--) {
        FOR(r, l, N) {
            if (l == r) dp[l][r] = a[l];
            else dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }
    cout << dp[0][N-1] << endl;
}

int main() {
  ll N;
    scanf("%lld",&N);
    vector<ll> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
  solve(N, move(a));
  return 0;
}

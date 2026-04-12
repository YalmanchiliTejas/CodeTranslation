#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll N;
vector<ll> a;
vector<vector<ll>> memo;

ll solve(ll l, ll r) {
    if (l >= r) {
        return 0;
    }
    if (memo[l][r] != INT_MIN) {
        return memo[l][r];
    }

    ll s1 = a[l] - solve(l + 1, r);
    ll s2 = a[r - 1] - solve(l, r - 1);
    return memo[l][r] = max(s1, s2);
}

int main() {
    cin >> N;
    a.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }

    memo.resize(N, vector<ll>(N + 1, INT_MIN));

    cout << solve(0, N) << endl;
}
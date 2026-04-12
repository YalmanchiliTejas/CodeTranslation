#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    vector<ll> S(N);
    for (ll i = 0; i < N; i++) {
        cin >> S[i];
    }

    auto isOK = [N](ll x) {
        return 0 <= x && x < N;
    };

    ll ans = 0;
    for (ll C = 1; C < N; C++) {
        vector<bool> visit(N, false);
        ll l = 0, r = N - 1;
        ll score = 0;
        while (true) {
            l += C;
            r -= C;
            if (!isOK(l) || !isOK(r) || visit[l] || visit[r] || l == r || r < C) {
                break;
            }
            visit[l] = visit[r] = true;
            score += S[l] + S[r];
            ans = max(ans, score);
        }
    }

    cout << ans << endl;
}
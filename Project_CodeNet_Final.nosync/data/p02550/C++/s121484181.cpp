#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    vector<ll> A(2 * M + 20);
    set<ll> S;
    S.insert(X);
    A[0] = X;
    ll l = 0, r = 0;
    for (ll i = 1; ; i++) {
        A[i] = ((A[i - 1] % M) * (A[i - 1] % M)) % M;
        if (S.find(A[i]) != S.end()) {
            for (ll j = 0; ; j++) {
                if (A[i] == A[j]) {
                    l = j;
                    r = i;
                    break;
                }
            }
        }
        if (r != 0) break;
        S.insert(A[i]);
    }
    ll w = r - l;
    ll s = 0;
    for (ll i = l; i < r; i++) s += A[i];
    ll ans = 0;
    ll n = 0;
    for (ll i = 0; i < l && n < N; i++) {
        ans += A[i];
        n++;
    }
    ans += s * ((N - n) / w);
    n += w * ((N - n) / w);
    for (ll i = l; n < N; i++) {
        ans += A[i];
        n++;
    }
    cout << ans << endl;
    return 0;
}

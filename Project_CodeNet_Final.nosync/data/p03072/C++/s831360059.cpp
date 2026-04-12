#pragma region noncode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#pragma endregion

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    ll ma = 0;
    rep(i, n) {
        if(ma <= h[i]) {
            ans++;
            ma = h[i];
        }
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979
#endif
#define deg_to_rad(deg) (((deg) / 360) * 2 * M_PI)
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<int, int> pi;
typedef long double ld;
typedef pair<long double, long double> pld;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, j, k, l;

    ll N;
    cin >> N;
    vll A(N);
    for(auto &e : A)
        cin >> e;
    ll ans = 0;
    ll sub = A[N - 1];
    for(i = N - 2; i >= 0; i--) {
        ans = (ans + A[i] * sub % MOD) % MOD;
        sub = (sub + A[i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}

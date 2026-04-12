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
    ll i, j, k;

    ll N, X, M;
    cin >> N >> X >> M;

    ll ans = 0;
    ll p = 0;
    ll x = X;
    vll E(M + 1, 0);
    bool f = false;
    while(1) {
        p++;
        if(p > N) {
            cout << ans << endl;
            return 0;
        }
        if(!f && E[x] > 0) {
            ll r_init = x;
            ll r_sum = 0;
            ll r_cnt = 0;
            while(1) {
                r_sum += x;
                r_cnt++;
                ans += x;
                if(x * x % M == r_init)
                    break;
                p++;
                if(p > N) {
                    cout << ans << endl;
                    return 0;
                }
                x = x * x % M;
            }
            ll num_r = (N - p) / r_cnt;
            ans += num_r * r_sum;
            p += num_r * r_cnt;
            f = true;
            for(i = p + 1; i <= N; i++) {
                x = x * x % M;
                ans += x;
            }
            cout << ans << endl;
            return 0;
        }
        ans += x;
        E[x] = 1;
        x = x * x % M;
    }

    return 0;
}

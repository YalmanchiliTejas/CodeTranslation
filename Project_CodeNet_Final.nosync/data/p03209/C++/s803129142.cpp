#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n, x; cin >> n >> x;

    ll target = x, ans = 0;
    vector<ll> paty(n + 1), sum(n + 1);
    paty[0] = sum[0] = 1;
    for(int i = 1; i <= n; ++i) {
        paty[i] = paty[i - 1] * 2 + 1;
        sum[i] = sum[i - 1] * 2 + 3;
    }
    for(int i = n; i >= 1; --i) {
        target -= 1;
        if(sum[i - 1] <= target) {
            ans += paty[i - 1];
            if(sum[i - 1] == target) {
                target = 0;
            } else {
                target -= sum[i - 1] + 1;
                ans += 1;
                if(target >= sum[i - 1]) {
                    target -= sum[i - 1] + 1;
                    ans += paty[i - 1];
                }
            }
        }
    }

    cout << ans << endl;
}

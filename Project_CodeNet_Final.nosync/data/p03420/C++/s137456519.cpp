#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, k;
    cin >> n >> k;
    ll res = 0;
    for (ll b = 1; b <= n; b++) {
        if (b <= k) continue;
        ll val = (n + 1) / b;
        //cout << b << " " << val << "\n";
        res += val * (b - k);
        ll x = val * b + k;
        if (x <= n) {
            res += n - x + 1;
        }
        if (!k) {
            res--;
        }
    }
    cout << res;
}

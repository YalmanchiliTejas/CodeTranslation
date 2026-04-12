#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP2(i,m,n) for (int i=m;i<(n);i++)
typedef long long ll;

ll A[1010];

void solve() {
    int N;
    cin >> N;
    REP(i, N) cin >> A[i];

    map<ll, ll> cnt;

    REP(i, N) {
        ll a = A[i];
        for (ll j = 2; j * j <= A[i]; ++j) {
            if (a % j == 0) {
                cnt[j] += A[i];
                while (a % j == 0) a /= j;
            }
        }
        if (a > 1) {
            cnt[a] += A[i];
        }
    }

    ll ans = 0;
    for (auto p: cnt) {
        if (p.first == 1) continue;
        ans = max(ans, p.second);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}


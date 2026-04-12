#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> suf(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
        suf[i] %= MOD;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += a[i] * (suf[i + 1]);
        ans %= MOD;
    }
    cout << ans << endl;


    return 0;
}


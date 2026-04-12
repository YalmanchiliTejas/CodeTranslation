/*
digu_J - Digvijay Janartha
NIT Hamirpur - INDIA
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long pre[N], vis[N];

void test() {
    long long n, x, m;
    cin >> n >> x >> m;
    long long cur = x, ans = 0;
    int fir = -1, last = -1;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        if (!cur) {
            cout << ans << "\n";
            return;
        }
        ++vis[cur];
        mp[cur] = i;
        pre[i] = pre[i - 1] + cur;
        ans += cur;
        cur *= cur;
        cur %= m;
        if (vis[cur]) {
            fir = mp[cur];
            last = i;
            break;
        }
    }
    if (last != -1) {
        n -= last;
        int len = last - fir + 1;
        long long amt = n / len;
        ans += amt * (pre[last] - pre[fir - 1]);
        n %= len;
        ans += pre[fir + n - 1] - pre[fir - 1];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef HOME
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; ++i) {
        test();
    }
    return 0;
}

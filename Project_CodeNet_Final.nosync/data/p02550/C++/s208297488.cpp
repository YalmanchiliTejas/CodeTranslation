#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
const int A = 2e5 + 2;
const int mod = 1e9 + 7;
ll n, x, m;
ll freq[A];
ll solve() {
    deque<ll> dq;
    ll cur = x, start = -1;
    dq.push_back(cur);
    for (int i = 1; i < min((ll)A, n); i++) {
        cur = (cur * cur) % m;
        freq[cur]++;
        if (freq[cur] == 2) {
            start = cur; break;
        }
        dq.push_back(cur);
    }
    ll ans = 0;
    while(!dq.empty()) {
        int cur = dq.front();
        if (cur == start) break;
        dq.pop_front();
        ans += cur, n--;
    }
    if (start == -1)
        return ans;
    ll sz = dq.size(), cnt = n / sz, rem = n % sz;
    for (int i = 0; i < dq.size(); i++) {
        ans += dq[i] * cnt;
        if (i < rem)
            ans += dq[i];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> x >> m;
    cout << solve();
    return 0;
}
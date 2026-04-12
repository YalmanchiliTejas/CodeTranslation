#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x, m;
    cin >> n >> x >> m;
    vector<int> a;
    a.pb(x);
    map<int, int> mp;
    mp[x] = 0;
    int ans = x;
    int idx_found = -1;
    for (int i = 1; i <= m; i++) {
        int y = a.back() * a.back();
        y %= m;
        if (mp.count(y)) {
            idx_found = mp[y];
            break;
        }
        a.pb(y);
        ans += y;
        mp[y] = i;
        if (a.size() == n) {
            return cout << ans, 0;
        }

    }
    int n_left = n - a.size();
    int sum_of_cycle = 0;
    for (int i = idx_found; i < a.size(); i++) {
        sum_of_cycle += a[i];
    }
    int cycle_size = a.size() - idx_found;
    int add = (n_left/cycle_size) * sum_of_cycle;
    int rem = n_left % cycle_size;
    ans += add;
    for (int i = idx_found; i < idx_found + rem; i++) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}


#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    multiset<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int now;
        cin >> now;
        now *= -1;
        if (a.empty() || *--a.end() <= now) a.insert(now);
        else {
            auto it = a.upper_bound(now);
            a.erase(it);
            a.insert(now);
        }
    }
    cout << a.size() << endl;
    return 0;
}

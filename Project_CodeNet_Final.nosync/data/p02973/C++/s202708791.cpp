#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
multiset <int> ms;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        ms.insert(a[i]);
        auto it = ms.upper_bound(a[i]);
        if (it != ms.end()) ms.erase(it);
    }
    cout << (int)ms.size();
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
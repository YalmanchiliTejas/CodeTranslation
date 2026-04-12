#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, ans = 0;

    vector<int> G[8];
    vector<int> a;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    for (int i = 1; i < n; i++) {
        a.push_back(i);
    }

    do {
        bool ok = true;
        for (int i = 0; i < n-1; i++) {
            bool tmp = false;
            if (!i) {
                for (auto e: G[0]) {
                    if (e == a[i]) { tmp = true; }
                }
            } else {
                for (auto e: G[a[i-1]]) {
                    if (e == a[i]) { tmp = true; }
                }
            }
            if (!tmp) { ok = false; }
        }
        if (ok) { ans++; }
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << endl;

    return 0;
}
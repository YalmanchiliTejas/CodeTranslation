#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.insert({min(a, b), max(a, b)});
    }

    int cnt = 0;
    vector<int> perm(n - 1);
    iota(perm.begin(), perm.end(), 2);

    do {
        bool ok = true;
        vector<int> path = {1};
        for (int v : perm) {
            path.push_back(v);
        }
        for (int i = 0; i < n - 1; i++) {
            int a = path[i], b = path[i + 1];
            if (edges.count({min(a, b), max(a, b)}) == 0) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << cnt << '\n';
}
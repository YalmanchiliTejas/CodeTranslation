#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p.at(i) = i;
    }

    vector<vector<bool>> G(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G.at(a).at(b) = true;
        G.at(b).at(a) = true;
    }

    int cnt = 0;
    do {
        if (p.at(0) != 0) break;
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (!G.at(p.at(i)).at(p.at(i + 1))) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
    } while (next_permutation(p.begin(), p.end()));

    cout << cnt << endl;
}   
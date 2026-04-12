#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int Solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        g[a - 1][b - 1] = g[b - 1][a - 1] = true;
    }

    vector<int> ord(n - 1);
    for (int i = 0; i < n - 1; ++i) ord[i] = i + 1;
    int res = 0;
    do {
        bool find = true;
        for (int i = 0, cur = 0; i < n - 1; ++i) {
            if (g[cur][ord[i]]) cur = ord[i];
            else { find = false; break; }
        }
        if (find) ++res;
    } while (next_permutation(ord.begin(), ord.end()));

    return res;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cout << Solve() << endl;

    return 0;
}

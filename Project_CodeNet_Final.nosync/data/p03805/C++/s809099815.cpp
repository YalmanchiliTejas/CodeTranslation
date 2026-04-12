#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool isInclude(const vector<int>& v, int x) {
    for (int i : v) if (i == x) return true;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>(0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> base(n);
    for (int j = 0; j < n; ++j) {
        base[j] = j;
    }
    int ans = 0;
    do {
        if (base[0] != 0) break;
        vector<bool> seen(n, false);
        seen[0] = true;
        for (int i = 0; i < n - 1; ++i) {
            if (isInclude(edge[base[i]], base[i + 1])) {
                seen[i + 1] = true;
            } else {
                break;
            }
        }
        bool test = true;
        for (bool b : seen) {
            if (!b) {
                test = false;
                break;
            }
        }
        if (test) ans++;
    } while (next_permutation(base.begin(), base.end()));
    cout << ans << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_next (int now, int next, vector<vector<int>> &nexts) {
    for (int i: nexts[now]) {
        if (i == next) return true;
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> next(n);
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        next[a].push_back(b);
        next[b].push_back(a);
    }
    int ans = 0;
    vector<int> order(n-1);
    for (int i=1; i<=n-1; i++) order[i-1] = i;
    do {
        bool can = check_next(0, order[0], next);
        if (!can) continue;
        for (int i=0; i<n-2; i++) {
            if (!check_next(order[i], order[i+1], next)) {
                can = false;
                break;
            }
        }
        if (can) ans++;
    } while (next_permutation(order.begin(), order.end()));
    cout << ans << endl;
}
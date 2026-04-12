#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int M = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a][b] = adj[b][a] = 1;
    }
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        v[i] = i + 1;
    }
    int ans = 0;
    do {
        int ok = 1;
        int pre = 0;
        for (int j : v) {
            if (!adj[pre][j]) {
                ok = 0;
                break;
            }
            pre = j;
        }
        ans += ok;
    } while(next_permutation(v.begin(), v.end()));
    cout << ans << "\n";
    return 0;
}

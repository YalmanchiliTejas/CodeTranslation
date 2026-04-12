#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    vector<int> order(n);
    rep(i, n) order[i] = i;

    int ans = 0;
    do {
        if (order[0] != 0) continue;
      
        rep(i, n - 1) {
            if (!graph[order[i]][order[i + 1]]) break;
            if (i == n - 2) ans++;
        }

    } while (next_permutation(order.begin(), order.end()));

    cout << ans << endl;
    return 0;
}
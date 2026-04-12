#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> route(n);
    iota(begin(route), end(route), 0);
    int ans = 0;
    do {
        int count = 1;
        for (int i = 0; i+1 < n; i++) {
            int from = route[i], to = route[i+1];
            if (find(begin(g[from]), end(g[from]), to) == end(g[from])) count = 0;
        }
        ans += count;
    } while (next_permutation(begin(route)+1, end(route)));

    cout << ans << endl;
}

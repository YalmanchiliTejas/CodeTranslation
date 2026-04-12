#include <functional>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int> > adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    function<bool(int, int)> dfs = [&](int i, int p) {
        if (p >= 0 && adj[i].size() == 1) return false;
        int c = 0;
        for (int j : adj[i]) if (j != p && !dfs(j, i)) c++;
        if (c > 1) {
            cout << "First\n";
            exit(0);
        }
        return c == 1;
    };
    cout << (dfs(0, -1) ? "Second\n" : "First\n");
}

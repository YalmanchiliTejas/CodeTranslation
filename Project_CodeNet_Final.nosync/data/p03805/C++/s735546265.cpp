#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<bool> > adj(n, vector<bool>(n, false));
    vector<int> v(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = true;
    }

    for (int i = 0; i < n; i++) { v[i] = i; }

    int ans = 0;
    do {
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (!adj[v[i - 1]][v[i]]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    } while (next_permutation(++v.begin(), v.end()));

    cout << ans << endl;
}
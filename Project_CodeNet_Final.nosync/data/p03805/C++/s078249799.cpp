#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int ans = 0;

void permutation(vector<unordered_set<int>>& adj, vector<int>& perm, vector<bool>& used, int level)
{
    if (level == perm.size()) {
        if (perm[0] != 0) return;
        int u = 0;
        for (int i = 1; i < perm.size(); i++) {
            if (!adj[u].count(perm[i])) return;
            u = perm[i];
        }
        ans++;
        return;
    }

    for (int i = 0; i < used.size(); i++) {
        if (used[i] == false) {
            used[i] = true;
            perm[level] = i;
            permutation(adj, perm, used, level + 1);
            used[i] = false;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> adj;
    adj.assign(n, unordered_set<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].insert(b - 1);
        adj[b - 1].insert(a - 1);
    }

    vector<int> perm(n, 0);
    vector<bool> choice(n, false);
    permutation(adj, perm, choice, 0);
    cout << ans << endl;
}
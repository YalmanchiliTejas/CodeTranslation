#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;
int n, parent[MaxN], cnt[MaxN], root;
vector <int> e[MaxN];

bool dfs(int node) {
    bool ans = true;
    for (auto x : e[node]) {
        if (x != parent[node]) {
            parent[x] = node;
            ans &= dfs(x);
        }
    }
    if (cnt[node] > 1 || cnt[node] == 0 && node == root)
       return false;
    if (cnt[node] == 0)
       cnt[parent[node]]++;
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        e[--a].push_back(--b);
        e[b].push_back(a);
    }
    if (n == 2) {
        cout << "Second";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (e[i].size() > 1) {
            parent[i] = i;
            root = i;
            if (dfs(i))
               cout << "Second";
            else
                cout << "First";
            return 0;
        }
    }
}

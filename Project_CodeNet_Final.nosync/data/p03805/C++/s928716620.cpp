#include <bits/stdc++.h>
using namespace std;
int n, m;
int num_visited = 0;
int ans = 0;
vector<int> visited;
vector<vector<int>> G;

void dfs(int now) {
    int next;
    visited.at(now) = 1;
    num_visited++;
    if(num_visited == n) {
        ans++;
    }
    for(int i = 0; i < G.at(now).size(); ++i) {
        next = G.at(now).at(i);
        if(!visited.at(next)) dfs(next);
    }
    visited.at(now) = 0;
    num_visited--;
}

int main() {
    cin >> n >> m;
    G = vector<vector<int>>(n);
    visited = vector<int>(n, 0);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    dfs(0);
    cout << ans << endl;
}
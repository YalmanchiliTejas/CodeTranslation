#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> to[8];
bool check[8];
int ans;

void dfs(int p, int cnt) {
    if (cnt == n) {
        ans++;
        return;
    }
    for (int np : to[p]) {
        if (!check[np]) {
            check[np] = true;
            dfs(np, cnt + 1);
            check[np] = false;
        }
    }
  	return;
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    check[0] = true;
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
vector<pair<int, int>> edge(4);
bool f = 0;
ll n, m, i, j, k;
string s[60];
bool ok[60][60];
void dfs(int p, pair<int, int> cur, int direct) {
    if(cur == edge[p]) {
        f = 1;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nxtx = dx[(i + direct) % 4] + cur.first, nxty = dy[(i + direct) % 4] + cur.second;
        if(nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m) {
            if(p==3 && nxtx==0 && nxty==0)f=1;
            if(s[nxtx][nxty] == '.') {
                s[nxtx][nxty] = '#';
                dfs(p, {nxtx, nxty}, (i + direct + 2) % 4);
                if(f) return;
            }
        }
    }
    return;
};

int main() {
    while(1) {
        for(i = 0; i < 60; i++) {
            for(j = 0; j < 60; j++) {
                ok[i][j] = 0;
            }
        }
        cin >> n >> m;
        if(n == 0) break;
        for(i = 0; i < n; i++) {
            cin >> s[i];
        }
        f=0;
        s[0][0]='#';
        edge[0] = {0, m - 1};
        edge[1] = {n - 1, m - 1};
        edge[2] = {n - 1, 0};
        edge[3] = {0, 0};
        dfs(0, edge[3], 1);
        if(f == 0) {
            cout << "NO" << endl;
            continue;
        }
        /*cout << "a" << endl;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                cout << s[i][j];
            }
            cout << endl;
        }*/
        f = 0;
        dfs(1, edge[0], 4);
        if(f == 0) {
            cout << "NO" << endl;
            continue;
        }

        f = 0;
        dfs(2, edge[1], 0);
        if(f == 0) {
            cout << "NO" << endl;
            continue;
        }

        f = 0;
        dfs(3, edge[2], 1);
        if(f == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int MAX = 6005;
const int INF = 1e9;
int dp[MAX][MAX];
int nxt[MAX][MAX];
int label[MAX];
vector<int> a;
vector<int> groups[MAX];
int id[MAX];
int n;
int ans = 0;
vector<int> loc[MAX];
void update(int x, int y, int val) {
    if (x > y) swap(x, y);
    assert(x < y);
    dp[x][y] = max(dp[x][y], val);
}
int check(int u, int v, int w){
    return (a[u] == a[v] && a[v] == a[w]);
}
void process(int u, int v, int w, int x, int y) {
    assert(u < v);
    assert(dp[u][v] != -1);
    update(u, w, dp[u][v] + check(v, x, y));
    update(u, x, dp[u][v] + check(v, w, y));
    update(u, y, dp[u][v] + check(v, x, w));
    update(v, w, dp[u][v] + check(u, x, y));
    update(v, x, dp[u][v] + check(u, w, y));
    update(v, y, dp[u][v] + check(u, w, x));
    update(w, x, dp[u][v] + check(u, v, y));
    update(w, y, dp[u][v] + check(u, v, x));
    update(x, y, dp[u][v] + check(u, v, w));
}
void go(int x, int y) {
    assert(x < y);
    if (label[y] == n - 1) {
        ans = max(ans, dp[x][y] + check(x, y, 3 * n - 1));
        return;
    }
    int cur_x = nxt[a[x]][label[y] + 1];
    int cur_y = nxt[a[y]][label[y] + 1];
    int group;
    if (cur_x != -1 && cur_y != -1) {
        group = min(label[cur_x], label[cur_y]);
        if (group == n) {
            ans = max(ans, dp[x][y] + check(x, y, 3 * n - 1));
        } else {
            process(x, y, groups[group][0], groups[group][1], groups[group][2]);
        }
    }
    group = label[y] + 1;
    process(x, y, groups[group][0], groups[group][1], groups[group][2]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> tmp(3 * n);
    for (int i = 0; i < 3 * n; i++) cin >> tmp[i];
    int add = 0;
    int _n = n;
    a.push_back(tmp[0]);
    a.push_back(tmp[1]);
    for (int i = 2; i < 3 * n - 1; i += 3) {
        if (tmp[i] == tmp[i + 1] && tmp[i + 1] == tmp[i + 2]) {
            _n--;
            add++;
        } else {
            a.push_back(tmp[i]);
            a.push_back(tmp[i + 1]);
            a.push_back(tmp[i + 2]);
        }
    }
    a.push_back(tmp.back());
    n = _n;
    if (n == 0) {
        cout << 0 + add << '\n';
        return 0;
    } else if (n == 1) {
        if (a[0] == a[1] && a[1] == a[2]) {
            cout << 1 + add << '\n';
        } else {
            cout << 0 + add << '\n';
        }
        return 0;
    }
    label[0] = label[1] = 0;
    for (int i = 2; i < 3 * n; i++) {
        label[i] = (i + 1) / 3;
        groups[label[i]].push_back(i);
    }
    for (int i = 0; i < 3 * n; i++) {
        id[i] = (int) loc[a[i]].size();
        loc[a[i]].push_back(i);
    }
    for (int i = 0; i < 3 * n; i++) {
        for (int j = 0; j < 3 * n; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            nxt[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if((int) loc[i].size() == 0) continue;
        for (int j: loc[i]) {
            int cur = label[j];
            while (cur != -1 && nxt[i][cur] == -1) {
                nxt[i][cur] = j;
                cur--;
            }
        }
    }
    dp[0][1] = 0;
    for (int i = 1; i < 3 * n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j][i] != -1) {
                go(j, i);
            }
        }
    }
    cout << ans + add << '\n';
    return 0;
}

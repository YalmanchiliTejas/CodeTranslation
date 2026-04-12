#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = (a); i <= (b); ++i)
#define ll long long

int a[52][52], d[5] = {0, 1, 0, -1, 0}, n, m;
int f(int i, int j) { return i * (m + 2) + j; }
vector<int> used;
void dfs(int i, int j) {
    if(!a[i][j]) return;
    if(used[f(i, j)]) return;
    used[f(i, j)] = true;
    rep(t, 4) { dfs(i + d[t], j + d[t + 1]); }
}
bool check() {
    used = vector<int>((n + 2) * (m + 2));
    dfs(1, 1);
    return used[f(1, m)] and used[f(n, 1)] and used[f(n, m)];
}
main() {
    while(1) {
        cin >> n >> m;
        if(!n) return 0;
        rep(i, n + 2) rep(j, m + 2) a[i][j] = 0;
        used = vector<int>((n + 2) * (m + 2));
        rep2(i, 1, n) rep2(j, 1, m) {
            char c;
            cin >> c;
            a[i][j] = c == '.';
        }
        if(check()) {
            bool flag = true;
            rep2(i, 1, n) rep2(j, 1, m) {
                if((i != 1 and i != n) or (j != 1 and j != m)) {
                    if(a[i][j]) {
                        a[i][j] = 0;
                        flag &= check();
                        a[i][j] = 1;
                    }
                }
            }
            cout << (flag ? "YES\n" : "NO\n");
        } else
            cout << "NO\n";
    }
}

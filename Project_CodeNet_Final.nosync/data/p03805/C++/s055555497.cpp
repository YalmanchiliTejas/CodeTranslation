#include <bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i = m; i < (int)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    rep(i, n) v[i] = i + 1;
    set<int> E[10];

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        E[a].insert(b);
        E[b].insert(a);
    }
    int cnt = 0;
    while (1) {
        bool can = true;
        rep(i, n - 1) {
            if (!E[v[i]].count(v[i + 1])) can = false;
        }
        if (can) cnt++;
        NP(v);
        if (v[0] != 1) break;
    }
    cout << cnt << endl;
    return 0;
}

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define chmin(x,y) x = min(x, y)
#define chmax(x,y) x = max(x, y)
vector<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
vector<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

int main () {
    int n, m; cin >> n >> m;
    vector<vector<bool>> to(n, vector<bool> (n, false));
    rep(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        to[a][b] = to[b][a] = true;
    }
    vector<int> vec(n);
    rep(i, n) vec[i] = i;
    int ans = 0;
    do {
        if (vec[0] != 0) continue;
        bool flag = true;
        rep(i, n-1) {
            if (!to[vec[i]][vec[i+1]]) flag = false;
        }
        if (flag) ans++;
    } while (next_permutation(all(vec)));

    cout << ans << endl;
    return 0;
}
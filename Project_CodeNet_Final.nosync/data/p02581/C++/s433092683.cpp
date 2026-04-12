#include <bits/stdc++.h>
using namespace std;
int n, a[10000], dp[2010][2010], margin = 1e8, allmax = 1e8, rowmax[2010];
void chmax(int &a, int b) { a = max(a, b); }
main() {
    cin >> n;
    for(int i = 0; i < 3 * n; ++i) cin >> a[i];
    dp[a[0]][a[1]] = rowmax[a[0]] = rowmax[a[1]] = margin;
    vector<tuple<int, int, int>> update;
    auto upd = [&](int i, int j, int k) {
        for(int _ = 0; _ < 2; _++) {
            update.emplace_back(i, j, k);
            swap(i, j);
        }
    };
    for(int i = 2; i < 3 * n; i += 3) {
        if(a[i] == a[i + 1] and a[i] == a[i + 2]) {
            margin--;
            continue;
        }
        for(int _ = 0; _ < 3; _++) {
            swap(a[i], a[i + 1]), swap(a[i + 1], a[i + 2]);
            upd(a[i], a[i + 1], max(allmax, dp[a[i + 2]][a[i + 2]] + 1));
            for(int j = 1; j <= n; ++j) {
                if(a[i + 1] == a[i + 2]) upd(j, a[i], dp[j][a[i + 1]] + 1);
                upd(j, a[i], rowmax[j]);
            }
        }
        for(auto [e, f, g] : update) chmax(dp[e][f], g), chmax(rowmax[e], g), chmax(allmax, g);
        update.clear();
    }
    cout << allmax - margin << endl;
}
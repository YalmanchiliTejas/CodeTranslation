#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M, a, b;
    cin >> N >> M;
    vector<vector<bool>> e(N, vector<bool>(N, false));
    rep(i, M) {
        cin >> a >> b;
        e[a - 1][b - 1] = true;
        e[b - 1][a - 1] = true;
    }
    vector<int> p(N - 1);
    rep(i, N - 1) p[i] = i + 1;
    int ans = 0;
    do {
        bool f = e[0][p[0]];
        rep(i, N - 2) {
            f &= e[p[i]][p[i + 1]];
        }
        if (f) ans++;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << "\n";
}
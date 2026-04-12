#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> G(N, vector<bool>(N));
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a][b] = true;
        G[b][a] = true;
    }

    vector<int> per(N);
    rep(i, N) per[i] = i;
    int ans = 0;
    do {
        if (per[0] != 0)
            break;
        bool flag = true;
        rep(i, N - 1) {
            if (!G[per[i]][per[i + 1]])
                flag = false;
        }
        if (flag)
            ans++;
    } while (next_permutation(per.begin(), per.end()));

    cout << ans << endl;

    return 0;
}
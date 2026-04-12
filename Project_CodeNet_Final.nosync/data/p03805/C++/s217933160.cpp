#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int N, M;
bool G[10][10];
ll ans = 0;
vector<int> path;
bool used[10];

void check() {
    rep(i, path.size() - 1) {
        if (!G[path[i]][path[i + 1]]) return;
    }
    ans++;
}

void f(int i) {
    if (i == N) {
        check();
        return;
    }

    if (i == 0) {
        used[0] = true;
        path.push_back(0);
        f(i + 1);
    } else {
        for (int j = 1; j < N; j++) {
            if (used[j]) continue;
            used[j] = true;
            path.push_back(j);
            f(i + 1);
            used[j] = false;
            path.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = true;
        G[b][a] = true;
    }
    f(0);
    cout << ans << endl;
}
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

void check() {
    if (path[0] != 0) return;
    rep(i, path.size() - 1) if (!G[path[i]][path[i + 1]]) return;
    ans++;
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
    rep(i, N) path.push_back(i);
    do {
        check();
    } while (next_permutation(path.begin(), path.end()));
    cout << ans << endl;
}
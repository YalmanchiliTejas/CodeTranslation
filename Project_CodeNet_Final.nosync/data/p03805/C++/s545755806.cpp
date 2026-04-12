#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;
vector<vector<bool>> Graph(10, vector<bool>(10, false));

int main() {
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        Graph[a][b] = true;
        Graph[b][a] = true;
    }

    ll ans = 0;

    vector<int> v;
    rep(i, N - 1) v.push_back(i + 1);
    do {
        bool ok = true;
        if (!Graph[0][v[0]]) continue;
        rep(i, N - 2) if (!Graph[v[i]][v[i + 1]]) ok = false;
        if (ok) ++ans;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
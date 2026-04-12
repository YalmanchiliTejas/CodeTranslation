#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

using Graph = vector<Vi>;
Graph g;
int N, M;

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    cin >> N >> M;
    g.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    for (int i = 0; i < N; i++) {
        sort(g[i].begin(), g[i].end());
    }

    ll ans = 0;
    Vi perm(N);
    for (int i = 0; i < N; i++) {
        perm[i] = i;
    }

    while (perm[0] == 0) {
        bool ok = true;
        for (int i = 1; i < N; i++) {
            if (!binary_search(g[perm[i - 1]].begin(), g[perm[i - 1]].end(), perm[i])) {
                ok = false;
            }
            if (!ok) {
                break;
            }
        }

        if (ok) {
            ++ans;
        }

        next_permutation(perm.begin(), perm.end());
    }

    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int N, M;
map<int, set<int>> G;

int solve1() {
    int cnt = 0;

    vi V(N);
    rep(i, N) V[i] = i;

    do {
        bool ok = true;
        if (V[0] != 0) continue;

        for (int i = 0; i < N - 1; i++) {
            if (!G[V[i]].count(V[i + 1])) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
    } while (next_permutation(V.begin(), V.end()));

    return cnt;
}

int main() {
    cin >> N >> M;

    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].insert(y);
        G[y].insert(x);
    }

    cout << solve1() << endl;
}

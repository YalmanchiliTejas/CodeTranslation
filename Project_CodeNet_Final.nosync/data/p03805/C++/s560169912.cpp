#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair< int, int >;

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector< int > > edge(N, vector< int >(N));
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    int ans = 0;
    vector< int > perm(N - 1);
    rep(i, N - 1) perm[i] = i + 1;
    do {
        bool feasible = true;
        int s = 0;
        rep(i, N - 1) {
            int n = perm[i];
            if (edge[s][n] != 1) {
                feasible = false;
                break;
            }
            s = n;
        }
        if (feasible) ++ans;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << endl;
}
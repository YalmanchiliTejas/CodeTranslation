#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)


int main()
{
    int N, M, a, b;
    cin >> N >> M;

    vector<vector<bool>> G(N, vector<bool>(N, false));
    rep(i,M) {
        cin >> a >> b; a--; b--;
        G[a][b] = G[b][a] = true;
    }

    vector<int> nodes(N);
    rep(i, N) nodes[i] = i;
    int ans = 0;
    do {
        if (nodes[0] != 0) continue;
        bool is_ok = true;
        rep(i, N-1) {
            if (!G[nodes[i]][nodes[i+1]]) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) ans++;
    } while (next_permutation(nodes.begin(), nodes.end()));
    cout << ans << endl;
}
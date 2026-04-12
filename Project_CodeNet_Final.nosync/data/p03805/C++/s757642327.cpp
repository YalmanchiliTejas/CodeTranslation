#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N, vector<int>(N,0));
    rep(i,0,M) {
        int a,b;
        cin >> a >> b;
        edge[a-1][b-1] = edge[b-1][a-1] = 1;
    }

    int ans = 0;
    vector<int> route(N-1);
    rep(i, 0, N-1) route[i] = i+1;
    do {
        bool can = true;
        if (!edge[0][route[0]]) can = false;
        rep(i,0,N-2) {
            if (!edge[route[i]][route[i+1]]) can = false;
        }
        if (can) ans++;
    } while (next_permutation(all(route)));

    cout << ans << endl;
}
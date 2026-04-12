#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
 
typedef long long ll;

int main() {
    int N, M, a, b;
    cin >> N >> M;
    vector<vector<bool>> edge(N, vector<bool>(N, false));
    rep(i, M) {
        cin >> a >> b;
        a--;
        b--;
        edge[a][b] = true;
        edge[b][a] = true;
    }
    vector<int> p(N - 1);
    rep(i, N - 1) p[i] = i + 1;
    int ans = 0;
    do {
        //rep(i, N - 1) cout << p[i];
        //cout << endl;
        if (!edge[0][p[0]]) continue;
        bool f = false;
        rep(i, N - 2) {
            if (!edge[p[i]][p[i + 1]]) {
                f = true;
                break;
            }
        }
        if (!f) ans++;
    } while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}
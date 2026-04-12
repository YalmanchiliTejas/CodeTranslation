#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    int a, b;
    rep(i, M) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, N) sort(G[i].begin(), G[i].end());
    vector<int> perm(N-1);
    rep(i, N-1) perm[i] = i+1;
    int ans = 0;
    do {
        int tmp = 0;
        bool flag = true;
        for (int i = 0; i < N-1; i++) {
            if (!binary_search(G[tmp].begin(), G[tmp].end(), perm[i])) {
                flag = false;
                break;
            }
            tmp = perm[i];
        }
        if (flag) ans++;
    }
    while(next_permutation(perm.begin(), perm.end()));
    cout << ans << endl;
}

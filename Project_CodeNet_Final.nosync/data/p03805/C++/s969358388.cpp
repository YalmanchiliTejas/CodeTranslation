#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

bool G[10][10]; // グラフを隣接行列で管理する。無方向なので対称にする。


int main() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a, --b; //全部-1してる
        G[a][b] = G[b][a] = true; //道が繋がっているところはture
    }

    // 順列
    vector<int> su(N);
    for (int i = 0; i < N; ++i) su[i] = i; //ベクトルに0〜n-1を格納

    // 順列を全部試すa
    int ans = 0;
    do {
        if (su[0] != 0) break;

        bool ok = true;
        for (int i = 0; i + 1 < N; ++i) {
            int from = su[i];
            int to = su[i+1];
            if (!G[from][to]) ok = false;
        }
        if (ok) ++ans;
    } while (next_permutation(su.begin(), su.end()));

    cout << ans << endl;
}
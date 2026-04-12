#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359
#define rep(i,n) for(int i=0; i<n; ++i)
#define INF 1001001001

typedef pair<int, int> P;

int main() {
    int n, m;
    cin >> n >> m;
    int path[n+1][n+1];
    memset(path, 0, sizeof(path));

    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        path[a][b] = 1;
        path[b][a] = 1;
    }

    int root[n];
    rep(i,n) root[i] = i;

    int ans = 0;
    do {
        bool flg = true;
        for (int i=0; i<n-1; ++i) {
            if (!path[root[i]][root[i+1]]) flg = false;
        }
        if (flg) ++ans;
    } while (next_permutation(root+1, root+n));

    cout << ans << endl;

    return 0;
}
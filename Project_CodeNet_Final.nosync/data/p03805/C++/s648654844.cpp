#include<bits/stdc++.h>
using namespace std;

//以下大槻型 ただし文字は自分のものに合わせた。

// グラフを隣接行列で管理する
bool edge[8][8];
 
int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        edge[x-1][y-1] = edge[y-1][x-1] = true;
    }
 
    // 順列
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
 
    // 順列を全部試す
    int ans = 0;

    
    do {
        if (ord[0] != 0) break;
 
        bool ok = true;
        for (int i = 0; i +1 < n; i++) {
            int from = ord[i];
            int to = ord[i+1];
            if (!edge[from][to]) ok = false;
        }
        if (ok) ans++;
      } while (next_permutation(ord.begin(), ord.end()));
 
    cout << ans << endl;
}

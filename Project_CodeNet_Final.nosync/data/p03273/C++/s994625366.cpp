#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W; cin >> H >> W;
    string grid[H]; rep(i, H) cin >> grid[i];
    set<int> row, col;
    rep(i, H){
        bool ok = true;
        rep(j, W) if(grid[i][j] == '#') ok = false;
        if(ok) row.insert(i);
    }
    rep(j, W){
        bool ok = true;
        rep(i, H) if(grid[i][j] == '#') ok = false;
        if(ok) col.insert(j);
    }
    rep(i, H){
        if(row.count(i)) continue;
        rep(j, W){
            if(col.count(j)) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
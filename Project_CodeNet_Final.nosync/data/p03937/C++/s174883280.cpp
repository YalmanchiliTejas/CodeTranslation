#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int H, W;
    cin >> H >> W;
    char grid[H][W];
    rep(i, H) rep(j, W) cin >> grid[i][j];
    int right_max = 0;
    bool res = true;
    rep(i, H){
        rep(j, W){
            if(grid[i][j] == '#' && j > right_max) right_max = j;
            else if(grid[i][j] == '#' && j < right_max) res = false;
        }
    }
    if(res) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}

void solve(){}
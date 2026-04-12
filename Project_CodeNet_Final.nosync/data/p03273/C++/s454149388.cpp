#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    int h, w;
    cin >> h >> w;
    int row = 0, col = 0;
    vector<string> grid(h);
    int grid_row = 0;
    int grid_col_now = w;
    set<int> skip_col;
    rep(i, h){
        string s;
        cin >> s;
        bool all_white = true;
        rep(j, w){
            if(s[j] == '#') all_white = false;
        }
        if(!all_white){
            grid[grid_row++] = s;
        }
    }

    rep(i, w){
        bool all_while = true;
        rep(j, grid_row){
            if(grid[j][i] == '#') all_while = false;
        }
        if(all_while){
            grid_col_now--;
            skip_col.insert(i);
        }
    }

    rep(i, grid_row){
        rep(j, w){
            if(skip_col.find(j) != skip_col.end()) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
}
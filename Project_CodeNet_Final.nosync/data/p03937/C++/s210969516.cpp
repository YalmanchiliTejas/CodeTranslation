#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W; cin >> H >> W;
    string S[H]; rep(i, H) cin >> S[i];
    char grid[H+2][W+2]; rep(i, H+2) rep(j, W+2) grid[i][j] = '.';
    rep(i, H) rep(j, W) grid[i+1][j+1] = S[i][j];
    int x = 1, y = 1;
    bool visited[H+2][W+2]; rep(i, H+2) rep(j, W+2) visited[i][j] = false;
    while(true){
        visited[x][y] = true;
        if(grid[x+1][y] == '#'){
            x++;
        }
        else if(grid[x][y+1] == '#'){
            y++;
        }
        else break;
    }
    bool ok = true;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(grid[i][j] == '#' && !visited[i][j]) ok = false;
        }
    }
    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
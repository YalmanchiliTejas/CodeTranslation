#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << endl;
#define popcnt __builtin_popcount

int H, W;
int dx[] = {1, 0}, dy[] = {0, 1};
char grid[10][10];

void dfs(int x, int y){
    bool flg = true;
    grid[y][x] = '.';
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx>=W||nx<0||ny>=H||ny<0)
            continue;
        if(grid[ny][nx]=='#'){
            flg = false;
            dfs(nx, ny);
            grid[ny][nx] = '#';
        }
    }

    if(flg){
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if(grid[i][j]=='#')
                    return;
                if(i==H-1&&j==W-1){
                    puts("Possible");
                    exit(0);
                }
            }
        }
    }

    return;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    dfs(0, 0);

    puts("Impossible");

    return 0;
}
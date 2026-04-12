#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)

int h,w;
string grid[10];
bool used[10][10];

int dfs(int y,int x){
    used[y][x] = true;
    int ret = 1;
    if(y+1 < h && grid[y+1][x]=='#' && !used[y+1][x]) ret += dfs(y+1,x);
    if(x+1 < w && grid[y][x+1]=='#' && !used[y+1][x]) ret += dfs(y,x+1);
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> h >> w;
    REP(i,h) cin >> grid[i];
    int way = 0, ans = 0;
    REP(i,h) REP(j,w) if(grid[i][j]=='#') ++way;
    ans = dfs(0,0);
    if(ans==way) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
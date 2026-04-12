#include <bits/stdc++.h>
#define FOR(i,bg,ed) for(ll i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
#define int long long
using namespace std;
typedef long long ll;
const int INF = 1e9;

int H, W;
char A[10][10];
bool visited[10][10];

bool dfs(int y, int x)
{
    visited[y][x] = true;
    
    if (y == H - 1 && x == W - 1){
        if (!(A[y-1][x]=='#' && !visited[y-1][x]) && !(A[y][x-1]=='#' && !visited[y][x-1])) {
            return true;
        }
    }
        
    if (x<W-1 && A[y][x+1]=='#' && y<H-1 && A[y+1][x]=='#') return false;
    else if ((0<x && !visited[y][x-1] && A[y][x-1]=='#') || (0<y && !visited[y-1][x] && A[y-1][x]=='#')) return false;
    else if (x<W-1 && A[y][x+1]=='#') return dfs(y, x+1);
    else if (y<H-1 && A[y+1][x]=='#') return dfs(y+1, x);
    else return false;
}

signed main()
{
    cin >> H >> W;
    REP(i,H) REP(j,W) cin >> A[i][j];

    if (dfs(0, 0)) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}

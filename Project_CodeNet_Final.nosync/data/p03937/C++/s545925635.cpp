#include <bits/stdc++.h>
using namespace std;

int h, w;
char grid[10][10];
bool visited[10][10], can = true;

bool isvalid(int x, int y)
{
    if(x>=1&&x<=h&&y>=1&&y<=w&&grid[x][y]=='#'&&!visited[x][y]) return true;
    return false;
}

void DFS(int x, int y)
{
    visited[x][y] = true;
    if(isvalid(x+1, y) && isvalid(x, y+1)) {
        can = false;
        return;
    }
    if(isvalid(x+1,y)) DFS(x+1, y);
    if(isvalid(x, y+1)) DFS(x, y+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> h >> w;
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++)
            cin >> grid[i][j];
    DFS(1,1);
    if(!can) {
        cout << "Impossible" << '\n';
        return 0;
    }
    for(int i=1; i<=h; i++)
        for(int j=1; j<=w; j++) {
            if(!visited[i][j]&&grid[i][j]=='#') {
                cout << "Impossible" << '\n';
                return 0;
            }
        }
    cout << "Possible" << '\n';

    return 0;
}

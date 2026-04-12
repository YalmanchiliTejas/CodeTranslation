#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
char grid[10][10];
int step[10][10];
int h, w;
int dx[4] = {1, 0};
int dy[4] = {0, 1};
bool Check()
{
    int cnt = 0;
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            if(grid[i][j] == '#')
                ++cnt;
    memset(step, -1, sizeof(step));
    step[1][1] = 1;
    queue<P> que;
    que.push({1, 1});
    while(!que.empty())
    {
        P now = que.front();
        que.pop();
        if(step[now.first][now.second] == cnt)
            return true;
        for(int i = 0; i < 2;++i)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if(grid[nx][ny] == '#')
            {
                que.push({nx, ny});
                step[nx][ny] = step[now.first][now.second] + 1;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d", &h, &w);
    for(int i = 1; i <= h; ++i)
        scanf("%s", grid[i] + 1);
    if(Check())
        puts("Possible");
    else
        puts("Impossible");
    return 0;
}
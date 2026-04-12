#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int x[4] = {0, 1,0,-1};
int y[4] = {1, 0,-1,0};
int h, w;
char s[8][8];
bool dfs(int a,int b){
    rep(k, 2)
    {
        int ny = a + y[k], nx = b + x[k];
        if (!(0 <= ny && ny < h) || !(0 <= nx && nx < w))
            continue;
        if (s[ny][nx] == '#')
        {
            s[ny][nx] = '.';
            if(dfs(ny, nx))return true;
            else return false;
        }
    }
    bool flag = true;

    rep(ci, h)
    {
        rep(cj, w)
        {
            if (s[ci][cj] == '#')
                flag = false;
        }
    }
    return flag;
}
int main()
{
    cin >> h >> w;
    rep(i, h)
    {
        rep(j,w){
            cin >> s[i][j];
        }
    }
    s[0][0] = '.';
    if (dfs(0,0))
    {
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Impossible" << endl;
}
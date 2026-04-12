#include <bits/stdc++.h>

using namespace std;

//#define _FILES
#define PB push_back
#define MP make_pair
#define X first
#define Y second

const int MAXN = 1000;
int f[MAXN][MAXN];
bool v[MAXN][MAXN];

void dfs(int x,int y)
{
    v[x][y] = true;
    if (f[x+1][y])
    {
        dfs(x+1, y);
        return;
    }

    if (f[x][y+1])
    {
        dfs(x, y+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    #ifdef _FILES
        freopen("","r",stdin);
        freopen("","w",stdout);
    #endif // _FILES
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        for (int j=0;j<m;j++)
        {
            if (s[j] == '#') f[i][j+1] = 1;
        }
    }
    dfs(1, 1);

    string ans = "Possible";
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if ((f[i][j]) && (!v[i][j]))
            {
                ans = "Impossible";
            }
        }
    }
    cout << ans << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1010;

int n, m;
char g[N][N];
bool st[N][N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> g[i];

    //row
    for(int i = 0; i < n; i++)
    {
        bool w = true;
        for(int j = 0; j < m; j++)
            if(g[i][j] == '#')
                w = false;
        if(w)
        {
            for(int j = 0; j < m; j++)
                st[i][j] = true;
        }
    }

    //col
    for(int i = 0; i < m; i++)
    {
        bool w = true;
        for(int j = 0; j < n; j++)
            if(g[j][i] == '#')
                w = false;
        if(w)
        {
            for(int j = 0; j < n; j++)
                st[j][i] = true;
        }
    }

    for(int i = 0; i < n; i++)
    {
        bool p = false;
        for(int j = 0; j < m; j++)
            if(!st[i][j])
            {
                cout << g[i][j];
                p = true;
            }
        if(p) puts("");
    }

    return 0;
}

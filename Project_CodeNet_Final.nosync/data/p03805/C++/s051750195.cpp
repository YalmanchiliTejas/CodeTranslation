#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n = 8;
vector<vector<int>> e(n+1, vector<int>(n+1));
vector<int> tmp(n+1);

int next(int a, vector<int> d)
{
    int count = 0;
    for(int i = 1; i < n + 1; i++)
    {
        if(d[i]) count++;
    }
    if(count == n)
    {
        ans++;
        return 0;
    }

    for(int i = 1; i < n + 1; i++)
    {
        if(e[a][i] == 1 && d[i] == 0)
        {
            d[i] = 1;
            
            next(i, d);
            d[i] = 0;
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }

    tmp[1] = 1;
    next(1, tmp);
    cout << ans << endl;
}

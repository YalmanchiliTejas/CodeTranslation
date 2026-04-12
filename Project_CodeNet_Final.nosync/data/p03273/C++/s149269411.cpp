#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    char c[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> c[i][j];
    }
    int cnt = 0;
    for (int j = 0; j < m; j++)
    {
        int cur = 0;
        for (int i = 0; i < n; i++) if (c[i][j] == '.' || c[i][j] == '-') cur++;
        if (cur == n)
        {
            for (int i = 0; i < n; i++) c[i][j] = '-';
        }
    }
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < m; j++) if (c[i][j] == '.' || c[i][j] == '-') cur++;
        if (cur == m)
        {
            for (int j = 0; j < m; j++) c[i][j] = '-';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) if (c[i][j] != '-') cout << c[i][j];
        cout << endl;
    }
}
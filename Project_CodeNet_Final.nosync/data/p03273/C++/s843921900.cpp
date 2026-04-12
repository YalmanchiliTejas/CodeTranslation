#include <bits/stdc++.h>
using namespace std;

string s[200];
int c[200], l[200];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (auto j : s[i]) l[i] += (j == '.');
        for (int j = 0; j < m; j++) c[j] += (s[i][j] == '.');
    }
    for (int i = 0; i < n; i++)
    {
        bool tag = 0;
        for (int j = 0; j < m; j++)
            if (l[i] != m && c[j] != n) cout << s[i][j], tag = 1;
        if (tag) puts("");
    }
    return 0;
}
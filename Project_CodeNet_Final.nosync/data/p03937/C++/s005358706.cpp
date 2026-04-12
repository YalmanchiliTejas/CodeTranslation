#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

string s[8];
int h, w;

int dfs(int i, int j)
{
    if (i == h || j == w)
        return 0;
    if (s[i][j] == '.')
        return 0;
    int x = dfs(i + 1, j);
    if (x == 0)
        x = dfs(i, j + 1);
    return x + 1;
}

int main()
{
    cin >> h >> w;
    int cnt = 0;
    for (int i = 0; i < h; ++i)
    {
        cin >> s[i];
        cnt += count(all(s[i]), '#');
    }
    int x = dfs(0, 0);
    if (x < h + w - 1 || cnt > x)
        cout << "Impossible";
    else
        cout << "Possible";
}

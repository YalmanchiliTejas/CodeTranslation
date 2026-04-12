#include <iostream>
using namespace std;
int dx[] = {0, 1};
int dy[] = {1, 0};
int n, m, flag = 0, flg = 0;
string s[100];
bool visited[100][100];
void dfs(int i, int j)
{
    if (i >= n || j >= m || s[i][j] == '.')
        return;
    visited[i][j] = true;
    if (i == (n - 1) && j == (m - 1))
        flag = 1;
    for (int k = 0; k < 2; k++)
    {
        if (flag)
            return;
        dfs(dx[k] + i, dy[k] + j);
    }
    if (!flag)
        visited[i][j] = false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#' && !visited[i][j])
            {
                flg = 1;
                break;
            }
        }
    }
    if (flg)
        cout << "Impossible" << endl;
    else
        cout << "Possible" << endl;
    return 0;
}
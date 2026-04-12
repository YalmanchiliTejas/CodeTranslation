#include <iostream>
#include <fstream>

using namespace std;

//ifstream fin ("contest.in");
//ofstream fout ("contest.out");

int n, m, np;
bool a[10][10];
char c;

void fil (int i, int j)
{
    if (a[i][j] == 0 || i < 1 || j < 1 || i > n || j > m)return;
    a[i][j] = 0;

    if (a[i + 1][j] == 1 && a[i][j + 1] == 1)
    {
        np = 1;
        return;
    }
    fil(i + 1, j);
    fil(i, j + 1);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == '#')a[i][j]=1;
        }
    }

    fil(1, 1);
    int ok =0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)ok = 1;

    if (np == 1)ok = 1;
    if (ok == 1)cout << "Impossible";
    else cout << "Possible";
    return 0;
}

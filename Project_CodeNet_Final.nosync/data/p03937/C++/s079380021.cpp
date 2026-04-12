#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string a[10];

int h, w;

bool dfs(int x, int y) {
    a[x][y] = '.';
    if (x == h - 1 && y == w - 1) {
        bool flag = false;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (a[i][j] == '#')
                    flag = true;
        if (!flag)
            return true;
    } else if (x == h - 1) {
        if (a[x][y + 1] == '#' && dfs(x, y + 1))
            return true;
    } else if (y == w - 1) {
        if (a[x + 1][y] == '#' && dfs(x + 1, y))
            return true;
    } else {
        if (a[x + 1][y] == '#' && dfs(x + 1, y))
            return true;
        if (a[x][y + 1] == '#' && dfs(x, y + 1))
            return true;
    }
    a[x][y] = '#';
    return false;
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> a[i];

    if (dfs(0, 0))
        cout << "Possible";
    else
        cout << "Impossible";

    return 0;
}
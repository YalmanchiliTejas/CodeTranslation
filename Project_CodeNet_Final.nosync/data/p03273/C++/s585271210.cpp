#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<bool> ignore_row(h, true);
    vector<bool> ignore_column(w, true);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '#')
            {
                ignore_row[i] = false;
                ignore_column[j] = false;
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        if (ignore_row[i]) continue;
        for (int j = 0; j < w; j++)
        {
            if (ignore_column[j]) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
}

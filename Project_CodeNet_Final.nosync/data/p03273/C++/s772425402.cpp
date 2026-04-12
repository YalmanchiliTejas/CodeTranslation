#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> result(h, vector<char>(w));
    vector<int> ignore_row(h, true);
    vector<int> ignore_column(w, true);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> result[i][j];
            if (result[i][j] == '#')
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
            cout << result[i][j];
        }
        cout << endl;
    }
}

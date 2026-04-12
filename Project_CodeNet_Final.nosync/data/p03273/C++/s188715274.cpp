#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    string a[H];
    bool row[H] = {};
    bool column[W] = {};

    for (int i = 0; i < H; i++)
    {
        cin >> a[i];
        for (int j = 0; j < W; j++)
        {
            if (a[i][j] == '#')
            {
                row[i] = true;
                column[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (row[i] && column[j])
            {
                cout << a[i][j];
            }
        }
        if (row[i])
        {
            cout << endl;
        }
    }
}

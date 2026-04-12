#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));
    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            cin >> a.at(r).at(c);
        }
    }

    vector<bool> can_remove_row(H, true);
    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            if (a.at(r).at(c) == '#')
            {
                can_remove_row.at(r) = false;
                break;
            }
        }
    }

    vector<bool> can_remove_col(W, true);
    for (int c = 0; c < W; c++)
    {
        for (int r = 0; r < H; r++)
        {
            if (a.at(r).at(c) == '#')
            {
                can_remove_col.at(c) = false;
                break;
            }
        }
    }

    for (int r = 0; r < H; r++)
    {
        if (can_remove_row.at(r))
        {
            continue;
        }
        for (int c = 0; c < W; c++)
        {
            if (can_remove_col.at(c))
            {
                continue;
            }
            cout << a.at(r).at(c);
        }
        cout << endl;
    }
}
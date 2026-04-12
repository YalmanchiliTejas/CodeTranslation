#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> a.at(i).at(j);
        }
    }

    vector<bool> remove_row(H, false);
    for (int i = 0; i < H; i++)
    {
        bool rm = true;
        for (int j = 0; j < W; j++)
        {
            if (a.at(i).at(j) == '#')
            {
                rm = false;
                break;
            }
        }
        if (rm)
        {
            remove_row.at(i) = true;
        }
    }

    vector<bool> remove_col(W, false);
    for (int j = 0; j < W; j++)
    {
        bool rm = true;
        for (int i = 0; i < H; i++)
        {
            if (a.at(i).at(j) == '#')
            {
                rm = false;
                break;
            }
        }
        if (rm)
        {
            remove_col.at(j) = true;
        }
    }

    for (int i = 0; i < H; i++)
    {
        if (remove_row.at(i))
        {
            continue;
        }
        else
        {
            for (int j = 0; j < W; j++)
            {
                if (remove_col.at(j))
                {
                    continue;
                }
                else
                {
                    cout << a.at(i).at(j);
                }
            }
            cout << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> table(H, vector<char>(W));
    vector<int> rows(H, 0);
    vector<int> cols(W, 0);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> table.at(i).at(j);
        }
    }

    for (int i = 0; i < H; i++)
    {
        bool s = true;
        if (table.at(i).at(0) == '.')
        {
            for (int j = 0; j < W - 1; j++)
            {
                if (table.at(i).at(j) != table.at(i).at(j + 1))
                {
                    s = false;
                    break;
                }
            }
        }
        else
        {
            s = false;
        }

        if (s == true)
        {
            rows.at(i) = 1;
        }
    }

    for (int i = 0; i < W; i++)
    {
        bool s = true;
        if (table.at(0).at(i) == '.')
        {
            for (int j = 0; j < H - 1; j++)
            {
                if (table.at(j).at(i) != table.at(j + 1).at(i))
                {
                    s = false;
                    break;
                }
            }
        }
        else
        {
            s = false;
        }

        if (s == true)
        {
            cols.at(i) = 1;
        }
    }

    for (int i = 0; i < H; i++)
    {
        if (rows.at(i) == 0)
        {
            for (int j = 0; j < W; j++)
            {
                if (cols.at(j) == 0)
                {
                    cout << table.at(i).at(j);
                }
            }
            cout << endl;
        }
    }

    return 0;
}
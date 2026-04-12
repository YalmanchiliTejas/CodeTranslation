#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> G(H, vector<char>(W));
    char c;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> G.at(i).at(j);
        }
    }

    vector<bool> X(W, false);
    vector<bool> Y(H, false);

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (G.at(i).at(j) == '#')
            {
                X.at(j) = true;
                Y.at(i) = true;
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        if (!Y.at(i))
        {
            continue;
        }
        for (int j = 0; j < W; j++)
        {
            if (X.at(j))
            {
                cout << G.at(i).at(j);
            }
        }

        cout << "" << endl;
    }

    return 0;
}
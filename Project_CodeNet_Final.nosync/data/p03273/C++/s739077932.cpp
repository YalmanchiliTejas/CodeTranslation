#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<string>> blocks(H, vector<string>(W));
    vector<bool> hasVerticalBlack(H, false);
    vector<bool> hasHorizontalBlack(W, false);

    for (int i = 0; i < H; i++)
    {
        string block;
        cin >> block;
        for (int j = 0; j < W; j++)
        {
            blocks.at(i).at(j) = block.at(j);
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (blocks.at(i).at(j) == "#")
            {
                hasVerticalBlack.at(i) = true;
                hasHorizontalBlack.at(j) = true;
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        if (hasVerticalBlack.at(i))
        {
            for (int j = 0; j < W; j++)
            {
                if(hasHorizontalBlack.at(j)) {
                    cout << blocks.at(i).at(j);
                }
            }
        cout << endl;
        }
    }

}
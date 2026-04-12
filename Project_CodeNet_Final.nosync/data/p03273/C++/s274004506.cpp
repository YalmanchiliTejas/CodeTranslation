#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    char S[110][110];
    cin >> H >> W;
    bool row[110] = {false};
    bool col[110] = {false};

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            char temp;
            cin >> temp;
            S[i][j] = temp;
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == '#')
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        if (row[i])
        {
            for (int j = 0; j < W; j++)
            {
                if (col[j])
                {
                    cout << S[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
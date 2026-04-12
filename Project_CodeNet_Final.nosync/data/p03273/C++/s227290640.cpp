#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    char t[h + 1][w + 1];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> t[i][j];
        }
    }

    bool f = false;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (t[i][j] == '#')
                break;
            if (j == w - 1)
                f = true;
        }
        if (f)
        {
            for (int j = 0; j < w; j++)
                t[i][j] = ' ';
            f = false;
        }
    }
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (t[j][i] == '#')
                break;
            if (j == h - 1)
                f = true;
        }
        if (f)
        {
            for (int j = 0; j < h; j++)
                t[j][i] = ' ';
            f = false;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (t[i][j] == ' ')
                continue;
            cout << t[i][j];
            f = true;
        }
        if (f)
            cout << endl;
        f = false;
    }
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    char table[h + 1][w + 1];
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            cin >> table[i][j];
        }
    }
    for (int i = 1; i <= h; ++i)
    {
        bool index = true;
        for (int j = 1; j <= w; ++j)
        {
            if (table[i][j] == '#')
            {
                index = false;
                break;
            }
        }
        if (index == true)
        {
            for (int j = 1; j <= w; ++j)
            {
                table[i][j] = 'e';
            }
        }
    }
    for (int i = 1; i <= w; ++i)
    {
        bool index = true;
        for (int j = 1; j <= h; ++j)
        {
            if (table[j][i] == '#')
            {
                index = false;
                break;
            }
        }
        if (index == true)
        {
            for (int j = 1; j <= h; ++j)
            {
                table[j][i] = 'e';
            }
        }
    }
    for (int i = 1; i <= h; ++i)
    {
        bool index = true;
        for (int j = 1; j <= w; ++j)
        {
            if (table[i][j] != 'e')
            {
                index = false;
                cout << table[i][j];
            }
        }
        if (index == true)
            cout << flush;
        else
            cout << endl;
    }
}
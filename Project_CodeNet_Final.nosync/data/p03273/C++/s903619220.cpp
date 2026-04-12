#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> a(H);
    for (auto &b : a)
    {
        b.resize(W);
        for (int i = 0; i < W; i++)
        {
            cin >> b[i];
        }
    }

    for (int i = 0; i < H; i++)
    {
        bool isDel = true;
        for (int j = 0; j < W; j++)
        {
            if (a[i][j] == '#')
            {
                isDel = false;
            }
        }
        if (isDel)
        {
            a.erase(a.begin() + i);
            H--;
            i--;
        }
    }

    for (int i = 0; i < W; i++)
    {
        bool isDel = true;
        for (int j = 0; j < H; j++)
        {
            if (a[j][i] == '#')
            {
                isDel = false;
            }
        }
        if (isDel)
        {
            for (int j = 0; j < H; j++)
            {
                a[j].erase(a[j].begin() + i);
            }
            W--;
            i--;
        }
    }

    for (auto b : a)
    {
        for (auto c : b)
        {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}

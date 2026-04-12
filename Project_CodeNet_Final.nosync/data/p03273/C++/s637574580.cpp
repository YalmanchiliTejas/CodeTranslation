#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++)
    {
        cin >> a.at(i);
    }

    vector<bool> skip_h(H, true);
    vector<bool> skip_w(W, true);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (a.at(i).at(j) == '#')
            {
                skip_h.at(i) = false;
                skip_w.at(j) = false;
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        if (skip_h.at(i))
        {
            continue;
        }
        for (int j = 0; j < W; j++)
        {
            if (skip_w.at(j))
            {
                continue;
            }
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
}
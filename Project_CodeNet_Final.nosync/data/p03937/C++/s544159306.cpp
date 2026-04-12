#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

bool ban[8][8];
int H, W;
bool search(int x, int y)
{
    //   cout << "x=" << x << endl;
    //   cout << "y=" << y << endl;
    //   cout << "H-1=" << H - 1 << endl;
    //   cout << "W-1=" << W - 1 << endl;
    if (ban[x][y] == false)
        return false;
    ban[x][y] = false;

    if (x == H - 1 && y == W - 1)
    {
        //       cout << "goal" << endl;
        return true;
    }
    else
    {
        bool ans = false;
        if (x - 1 >= 0 && x - 1 < H && ban[x - 1][y] == true)
        {
            //         cout << "false1" << endl;
            ans = false;
        }
        else if (y - 1 >= 0 && y - 1 < W && ban[x][y - 1] == true)
        {
            //         cout << "false2" << endl;
            ans = false;
        }
        else
        {
            bool down = (x + 1 < H && ban[x + 1][y] == true);
            bool right = (y + 1 < W && ban[x][y + 1] == true);
            if (down && right)
                ans = false;
            else if (down)
            {
                ans = search(x + 1, y);
            }
            else if (right)
            {
                ans = search(x, y + 1);
            }
        }
        return ans;
    }
}

int main()
{
    cin >> H >> W;
    //   char a[H][W];
    int counter = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                ban[i][j] = true;
                counter++;
            }
            else
                ban[i][j] = false;
        }
    }
    if (counter == H + W - 1)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;

    int x = 0, y = 0;
    bool ans = search(x, y);
    if (ans == true)
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
}
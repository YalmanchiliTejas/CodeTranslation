#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long int ll;

ll a, b, c, d, e, f, g, h, i, k, l;
ll N, H, W;
bool r_white[100];
bool c_white[100];
char grid[100][100];

void input()
{
    cin >> H >> W;

    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++)
        {
            grid[i][j] = s[j];
        }
    }
}

void solve()
{
    bool is_white;
    for (int i = 0; i < H; i++)
    {
        is_white = true;
        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == '#')
            {
                is_white = false;
            }
        }
        if (is_white)
            r_white[i] = true;
    }

    for (int i = 0; i < W; i++)
    {
        is_white = true;
        for (int j = 0; j < H; j++)
        {
            if (grid[j][i] == '#')
            {
                is_white = false;
            }
        }
        if (is_white)
            c_white[i] = true;
    }
}

int main()
{
    input();
    solve();

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (r_white[i] || c_white[j])
            {
                continue;
            }
            cout << grid[i][j];
        }
        if (!r_white[i])
            cout << '\n';
    }
}
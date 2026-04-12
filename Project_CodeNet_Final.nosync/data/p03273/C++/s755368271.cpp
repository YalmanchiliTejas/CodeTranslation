#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> list(H, vector<char>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> list[i][j];
    vector<bool> Hb(H, false), Wb(W, false);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (list[i][j] == '#')
            {
                Hb[i] = true;
                Wb[j] = true;
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        if(Hb[i])
        {
            for (int j = 0; j < W; j++)
            {
                if(Wb[j])
                    cout << list[i][j];
            }
            cout << endl;
        }
    }
}
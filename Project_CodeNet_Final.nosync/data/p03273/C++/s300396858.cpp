#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

int H, W;
char board[110][110];
set <int> h, w;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> H >> W;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '#')
            {
                h.insert(i);
                w.insert(j);
            }
        }

    for (set<int>::iterator it = h.begin(); it != h.end(); it++)
    {
        int x = *it;
        for (set<int>::iterator it2 = w.begin(); it2 != w.end(); it2++)
        {
            int y = *it2;
            cout << board[x][y];
        }
        cout << "\n";
    }
}
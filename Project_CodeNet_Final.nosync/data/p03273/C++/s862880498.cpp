#include <iostream>
#include <vector>
using namespace std;
const long INF = 1e9;
const long MOD = 1e9 + 7;
#define repi(i, n, init) for (int i = init; i < int(n); i++)

int main()
{
    int h, w, cnt = 0;
    cin >> h >> w;
    vector<vector<char>> Grid(h, vector<char>(w));
    vector<vector<bool>> check(h, vector<bool>(w, true));

    repi(i, h, 0)
    {
        cnt = 0;
        repi(j, w, 0)
        {
            cin >> Grid[i][j];
            if (Grid[i][j] == '.')
            {
                cnt++;
            }
        }
        if (cnt == w)
        {
            repi(j, w, 0)
            {
                check[i][j] = false;
            }
        }
    }
    repi(i, w, 0)
    {
        cnt = 0;
        repi(j, h, 0)
        {
            if (Grid[j][i] == '.')
            {
                cnt++;
            }
        }
        if (cnt == h)
        {
            repi(j, h, 0)
            {
                check[j][i] = false;
            }
        }
    }
    repi(i, h, 0)
    {
        bool print = false;
        repi(j, w, 0)
        {
            if (check[i][j])
            {
                print = true;
                cout << Grid[i][j];
            }
        }
        cout << (print ? "\n" : "");
    }

    return 0;
}
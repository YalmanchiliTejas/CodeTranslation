#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;

int main()
{
    int h, w;
    cin >> h >> w;
    vvc b(h);
    for (int r = 0; r < h; r++)
    {
        b[r] = vc(w);
        for (int c = 0; c < w; c++)
        {
            cin >> b[r][c];
        }
    }

    vi rows;
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            if (b[r][c] == '#')
            {
                rows.push_back(r);
                break;
            }
        }
    }

    vi cols;
    for (int c = 0; c < w; c++)
    {
        for (int r = 0; r < h; r++)
        {
            if (b[r][c] == '#')
            {
                cols.push_back(c);
                break;
            }
        }
    }

    for (auto r : rows)
    {
        for (auto c : cols)
        {
            cout << b[r][c];
        }
        cout << endl;
    }

    return 0;
}

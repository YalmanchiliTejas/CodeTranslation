#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define SORT(A) sort(A.begin(), A.end())
#define SORTG(A) sort(A.begin(), A.end(), greater<int>())
using namespace std;
typedef long long ll;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> table;
    string tmp;
    bool flg;
    rep(y, H)
    {
        cin >> tmp;
        for (char c : tmp)
        {
            if (c == '#')
            {
                table.push_back(tmp);
                break;
            }
        }
    }
    vector<bool> dlt(W, true);
    rep(x, W)
    {
        rep(y, table.size())
        {
            if (table.at(y).at(x) == '#')
            {
                dlt.at(x) = false;
                break;
            }
        }
    }
    for (string y : table)
    {
        rep(x, W)
        {
            if (dlt.at(x) == false) cout << y.at(x);
        }
        cout << endl;
    }

    return 0;
}
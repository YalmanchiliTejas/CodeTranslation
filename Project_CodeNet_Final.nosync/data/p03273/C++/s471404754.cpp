#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> data(H);
    vector<bool> row(H, false);
    vector<bool> col(W, false);

    REP(i, H)
    {
        cin >> data.at(i);

        REP(j, W)
        {
            if (data.at(i).at(j) == '#')
            {
                row.at(i) = true;
                col.at(j) = true;
            }
        }
    }

    REP(i, H)
    {
        if (row.at(i) == true)
        {
            REP(j, W)
            {
                if (col.at(j) == true)
                {
                    cout << data.at(i).at(j);
                }
            }

            cout << endl;
        }
    }
}
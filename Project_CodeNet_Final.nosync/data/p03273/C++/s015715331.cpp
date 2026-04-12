#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int main()
{
    int h, w, tate[110] = {}, yoko[110] = {};
    char a[110][110];
    cin >> h >> w;
    REP(i, h)
    {
        bool all = true;
        REP(j, w)
        {
            cin >> a[i][j];

            if (a[i][j] == '#')
                all = false;
        }

        if (all)
            yoko[i] = 1;
    }

    REP(j, w)
    {
        bool all = true;
        REP(i, h)
        {
            if (a[i][j] == '#')
                all = false;
        }
        if (all)
            tate[j] = 1;
    }

    REP(i, h)
    {
        if (yoko[i] == 1)
            continue;

        REP(j, w)
        {
            if (tate[j] == 0)
                cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
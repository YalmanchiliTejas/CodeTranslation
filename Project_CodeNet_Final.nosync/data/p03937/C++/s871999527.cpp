#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for(int i = (s); i <= (f); ++i)
#define for1(i, f, s) for(int i = (f); i >= (s); --i)
#define fora(i, x) for (auto i : x)
#define show(x) cout << #x << " = " << x << " ";
#define skip continue;
#define pb push_back
#define _1 first
#define _2 second

typedef long long ll;

const int N3 = 1e3 + 5;
const int N4 = 1e4 + 5;
const int N5 = 1e5 + 5;
const int N6 = 1e6 + 5;
const int N7 = 1e7 + 5;
const int N8 = 1e8 + 5;
const int N9 = 1e9 + 5;
const int mod = N9 + 2;

char a[10][10];

int lt_x, lt_y, n, m, now[10][10];

int cnt;

int main()
{
    cin >> n >> m;
    forn (i, 1, n)
        forn (j, 1, m)
            cin >> a[i][j];

    if (a[n][m] != '#')
        return !(cout << "Impossible");
    forn (i, 1, n)
    {
        forn (j, 1, m)
        {
            if (a[i][j] == '#' && a[i + 1][j] == '#' && a[i][j + 1] == '#' && a[i + 1][j + 1])
                return !(cout << "Impossible");
            if (i != 1 && j != 1)
            {
                if (a[i][j] == '#' && a[i - 1][j] != '#' && a[i][j - 1] != '#')
                    return !(cout << "Impossible");
            }
        }
    }
    cout << "Possible";

}

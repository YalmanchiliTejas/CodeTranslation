#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <vector>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (int i = a; i < n; i++)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define vi vector<int>
#define sort_v(a) sort(a.begin(), a.end())

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vi x, y;

bool inx(int n, vi z)
{
    rep(i, 0, z.size())
    {
        if (z[i] == n)
            return true;
    }
    return false;
}

int main()
{
    int h, w;
    cin >> h >> w;
    string a[h];
    rep(i, 0, h)
    {
        cin >> a[i];
    }

    rep(i, 0, h)
    {
        bool white = true;
        rep(j, 0, w)
        {
            if (a[i][j] == '#')
            {
                white = false;
                break;
            }
        }
        if (white)
            y.push_back(i);
    }
    rep(i, 0, w)
    {
        bool white = true;
        rep(j, 0, h)
        {
            if (a[j][i] == '#')
            {
                white = false;
                break;
            }
        }
        if (white)
            x.push_back(i);
    }
    rep(i, 0, h)
    {
        bool f = false;
        rep(j, 0, w)
        {
            if (!inx(j, x) && !inx(i, y))
                cout << a[i][j];
            if (inx(i, y))
                f = true;
        }
        if (!f)
            cout << endl;
    }
}

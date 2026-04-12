#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
int H, W;
char a[200][200];

int main()
{
    cin >> H >> W;
    repe(i, 1, H)
    {
        repe(j, 1, W)
        {
            cin >> a[i][j];
        }
    }

    repe(i, 1, H)
    {
        bool flag = true;
        repe(j, 1, W)
        {
            if (a[i][j] == '#')
            {
                flag = false;
            }
        }
        if (flag)
        {
            repe(j, 1, W)
            {
                a[i][j] = '*';
            }
        }
    }

    repe(j, 1, W)
    {
        bool flag = true;
        repe(i, 1, H)
        {
            if (a[i][j] == '#')
            {
                flag = false;
            }
        }
        if (flag)
        {
            repe(i, 1, H)
            {
                a[i][j] = '*';
            }
        }
    }
    repe(i, 1, H)
    {
        bool flag = false;
        repe(j, 1, W)
        {
            if (a[i][j] != '*')
            {
                flag = true;
                cout << a[i][j];
            }
        }
        if (flag)
        {
            cout << endl;
        }
    }
}

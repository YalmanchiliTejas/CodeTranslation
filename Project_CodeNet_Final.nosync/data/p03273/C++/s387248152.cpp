/*
 * @Author: hesorchen
 * @Date: 2020-07-03 17:05:01
 * @LastEditTime: 2020-09-04 19:10:39
 * @Description: https://hesorchen.github.io/
 */
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define PI acos(-1)
#define PB push_back
#define ll long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define pll pair<ll, ll>
#define lowbit(abcd) (abcd & (-abcd))
#define max(a, b) ((a > b) ? (a) : (b))
#define min(a, b) ((a < b) ? (a) : (b))

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define FRE                              \
    {                                    \
        freopen("in.txt", "r", stdin);   \
        freopen("out.txt", "w", stdout); \
    }

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
//head==============================================================================

char mp[110][110];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", mp[i] + 1);
    while (1)
    {
        int heng, zong;
        heng = zong = 0;
        for (int i = 1; i <= n; i++)
        {
            int f2 = 0;
            for (int j = 1; j <= m; j++)
            {

                if (mp[i][j] == '#')
                    f2 = 1;
            }
            if (!f2)
            {
                heng = i;
                break;
            }
        }
        if (heng)
        {
            for (int i = heng; i < n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    mp[i][j] = mp[i + 1][j];
                }
            }
            n--;
            continue;
        }

        for (int j = 1; j <= m; j++)
        {
            int f2 = 0;
            for (int i = 1; i <= n; i++)
            {
                // if (mp[i][j] == '.')
                //     f1 = 1;
                if (mp[i][j] == '#')
                    f2 = 1;
            }
            if (!f2)
            {
                zong = j;
                break;
            }
        }
        if (zong)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = zong; j < m; j++)
                {
                    mp[i][j] = mp[i][j + 1];
                }
            }
            m--;
            continue;
        }
        break;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%c", mp[i][j]);
        printf("\n");
    }

    return 0;
}
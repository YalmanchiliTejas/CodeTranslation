/*
 * @Author: hesorchen
 * @Date: 2020-07-03 17:05:01
 * @LastEditTime: 2020-09-04 19:03:07
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

int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("%d", (x - z) / (y + z));

    return 0;
}
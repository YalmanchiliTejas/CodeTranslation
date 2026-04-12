#include <bits/stdc++.h>
using namespace std;
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
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//-----------------------------------------

ll patty[60];
ll burger[60];

ll f(int level, ll x)
{
    if (level == 0)
    {
        if (x <= 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    if (x <= 1 + burger[level - 1])
    {
        return f(level - 1, x - 1);
    }
    else
    {
        return patty[level - 1] + 1 + f(level - 1, x - 2 - burger[level - 1]);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll x;
    cin >> n >> x;
    patty[0] = 1;
    burger[0] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        burger[i + 1] = burger[i] * 2 + 3;
        patty[i + 1] = 2 * patty[i] + 1;
    }

    cout << f(n, x) << endl;
}
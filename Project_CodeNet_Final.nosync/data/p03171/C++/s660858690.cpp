#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <functional>
#include <numeric>
#include <chrono>
#include <cstdlib>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
const double pi = acos(-1);
#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EPS 1e-4
// bool operator<(const pair<int, int> &a, const pair<int, int> &b)
// {
//     if (a.first == b.first)
//         return a.second < b.second;
//     return a.first < b.first;
// };

/*unsigned int xor128(void)
{
    static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned int t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
unsigned int xor128rnd(unsigned int m)
{
    return xor128() % m;
}*/

bool operator<(const pair<ll, ll> &a, const pair<ll, ll> &b)
{

    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}
int arr[3010];
ll dp[3010][3010];

ll f(int l, int r)
{
    if (r < l)
        return 0;

    ll memo = dp[l][r];
    if (memo != 100000000000)
        return memo;

    return dp[l][r] = max(arr[l] - f(l + 1, r), arr[r] - f(l, r - 1));
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 3010; ++i)
    {
        for (int j = 0; j < 3010; ++j)
        {
            dp[i][j] = 100000000000;
        }
    }
    cout << f(0, N - 1) << endl;
    return 0;
}

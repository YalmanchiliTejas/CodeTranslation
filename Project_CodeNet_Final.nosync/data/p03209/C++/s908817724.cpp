#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <tuple>
using ll = long long;
using namespace std;
vector<int> v;
ll N, X;
ll ans = 0;
ll a[51], p[51];
ll dfs(ll t, ll s)
{
    if (t == 0)
        return 1;

    if (s == 1)
        return 0;
    else if (s > 1 && s <= a[t - 1] + 1)
        return dfs(t - 1, s - 1);
    else if (s == a[t - 1] + 2)
        return p[t - 1] + 1;
    else if (s > a[t - 1] + 2 && s <= 2 + 2 * a[t - 1])
        return p[t - 1] + 1 + dfs(t - 1, s - 2 - a[t - 1]);
    else if (s == 3 + 2 * a[t - 1])
        return 2 * p[t - 1] + 1;
}

int main(void)
{

    cin >> N >> X;
    if (X == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    a[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        a[i] = a[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }

    ans = dfs(N, X);

    cout << ans << endl;
    return 0;
}
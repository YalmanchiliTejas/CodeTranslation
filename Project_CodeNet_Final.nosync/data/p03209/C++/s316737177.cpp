#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <ctime>
#include <limits>
#include <iomanip>
#include <functional>
#include <array>
#include <climits>

using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

ll a[51] = { 1 };
ll p[51] = { 1 };

ll f(ll n, ll x)
{
    if (n == 0)
    {
        return x <= 0 ? 0 : 1;
    }
    else if (x <= 1 + a[n - 1])
    {
        return f(n - 1, x - 1);
    }
    else
    {
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
    }
}

int main()
{
    ll n, x;
    cin >> n >> x;

    for (ll i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }

    ll sum = f(n, x);
    cout << sum << endl;
    return 0;
}


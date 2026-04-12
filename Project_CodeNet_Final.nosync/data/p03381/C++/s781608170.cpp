#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define ALL(v) v.begin(),v.end()

ll gcd(ll x, ll y)
{
    while (y > 0)
    {
        ll tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

ll lcm(ll x, ll y)
{
    return x / gcd(x, y) * y;
}

ll facctorialMethod(ll k)
{
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum %= 1000000007;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<ll> a(n), b;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    ll m1 = b[n / 2 - 1], m2 = b[n / 2];
    for (ll i = 0; i < n; i++)
    {
        cout << (a[i] <= m1 ? m2 : m1) << endl;
    }
}
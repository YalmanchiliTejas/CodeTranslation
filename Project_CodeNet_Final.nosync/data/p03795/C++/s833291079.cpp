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

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    cout << 800 * n - 200 * (n / 15) << endl;
}
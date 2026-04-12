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
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>
#include <unordered_map>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define SW(x) setw(x) // 桁数指定
#define SF(c) setfill(c) // 埋め文字指定('0')
#define ALL(v) v.begin(), v.end()

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    deque<ll> p;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        if (i % 2 == 0)
        {
            p.push_back(a);
        }
        else
        {
            p.push_front(a);
        }
    }
    if (n % 2 == 0)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << p[i];
            if (i != n - 1)
            {
                cout << ' ';
            }
        }
    }
    else
    {
        for (ll i = n - 1; i >= 0; i--)
        {
            cout << p[i];
            if (i != 0)
            {
                cout << ' ';
            }
        }
    }
    cout << endl;
}

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
#define SW(x) setw(x)    // 桁数指定
#define SF(c) setfill(c) // 埋め文字指定('0')
#define ALL(v) v.begin(), v.end()

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;

    ll sum = a.back();
    // for (ll i = 1; i < n; i++)
    // {
    //     sum += a[i];
    //     sum %= 1000000007;
    // }

    for (ll i = n - 2; i >= 0; i--)
    {
        ll temp = sum * a[i] % 1000000007;
        ans += temp;
        ans %= 1000000007;
        sum += a[i];
        sum %= 1000000007;
    }

    cout << ans << endl;
}
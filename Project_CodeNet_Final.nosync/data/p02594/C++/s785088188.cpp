
#define INF 10000000000
#define MOD 1000000007

#if 1   // use_templates

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, up) for (ll i = 0; i < (up); ++i)
#define repp(i, up) for (ll i = 0; i <= (up); ++i)
#define rrep(i, lo, up) for (ll i = (lo); i < (up); ++i)
#define rrepp(i, lo, up) for (ll i = (lo); i <= (up); ++i)
#define eep(i, lo, up) for ((i) = (lo); (i) < (up); ++(i))
#define eepp(i, lo, up) for ((i) = (lo); (i) <= (up); ++(i))
#define feach(it, vec) for (auto it = (vec).begin(); it != (vec).end(); ++it)


ll gcd(ll a, ll b);

ll gcd(ll a, ll b)
{
    if (a < b) {
        return gcd(b, a);
    }
    ll r;
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b;
}

#endif  // end of use_templates


int main()
{
    ll x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

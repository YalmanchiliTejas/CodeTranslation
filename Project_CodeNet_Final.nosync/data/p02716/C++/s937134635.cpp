#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, up) for (ll i = 0; i < up; ++i)
#define repp(i, up) for (ll i = 0; i <= up; ++i)
#define rrep(i, lo, up) for (ll i = lo; i < up; ++i)
#define rrepp(i, lo, up) for (ll i = lo; i <= up; ++i)

#define rdi(i) ll i; scanf("%lld", &i)
#define rds(s) string s; cin >> s
#define rdc(c) char c; cin >> c

#define INF 10000000000
#define MOD 1000000007

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

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    rrepp(i, 1, n) {
        scanf("%lld", &a[i]);
    }

    if (n == 2) {
        cout << max(a[1], a[2]) << endl;
        return 0;
    }
    vector<ll> dp00(n + 1), dp01(n + 1), dp02(n + 1), dp10(n + 1), dp11(n + 1), dp12(n + 1);
    dp00[1] = 0;
    dp01[1] = 0;
    dp02[1] = 0;
    dp10[1] = 0;
    dp11[1] = 0;
    dp12[1] = 0;
    dp00[2] = a[1];
    dp01[2] = 0;
    dp02[2] = 0;
    dp10[2] = a[2];
    dp11[2] = 0;
    dp12[2] = 0;
    dp00[3] = 0;
    dp01[3] = max(a[1], a[2]);
    dp02[3] = 0;
    dp10[3] = a[1] + a[3];
    dp11[3] = a[3];
    dp12[3] = 0;
    rrepp(i, 4, n) {
        if (i % 2 == 0) {
            dp00[i] = dp10[i - 1];
            dp01[i] = max(dp01[i - 1], dp11[i - 1]);
            dp02[i] = max(dp02[i - 1], dp12[i - 1]);
            dp10[i] = dp01[i - 1] + a[i];
            dp11[i] = dp02[i - 1] + a[i];
            dp12[i] = 0;
        } else {
            dp00[i] = 0;
            dp01[i] = max(dp00[i - 1], dp10[i - 1]);
            dp02[i] = max(dp01[i - 1], dp11[i - 1]);
            dp10[i] = dp00[i - 1] + a[i];
            dp11[i] = dp01[i - 1] + a[i];
            dp12[i] = dp02[i - 1] + a[i];
        }
    }
    if (n % 2 == 0) {
        cout << max(dp00[n], dp10[n]) << endl;
    } else {
        cout << max(dp01[n], dp11[n]) << endl;
    }
    return 0;
}
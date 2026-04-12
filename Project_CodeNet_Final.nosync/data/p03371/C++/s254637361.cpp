#include "bits/stdc++.h"
using namespace std;
#define forn(i, x, n) for (int i = x; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
typedef long double ld;
typedef long long ll;

int main() {
    ll a, b, c, x, y;
    scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &x, &y);
    ll cost = 0;
    if (a + b >= 2*c) {
        while (x > 0 && y > 0) {
            cost += 2*c;
            x--;
            y--;
        }
        while (x > 0 && a >= 2*c) {
            cost += 2*c;
            x--;
            y--;
        }
        while (y > 0 && b >= 2*c) {
            cost += 2*c;
            x--;
            y--;
        }
    }
    while (x > 0) {
        cost += a;
        x--;
    }
    while (y > 0) {
        cost += b;
        y--;
    }
    printf("%lld\n", cost);
    return 0;
}

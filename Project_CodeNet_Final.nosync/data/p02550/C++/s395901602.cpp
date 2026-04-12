#include <iostream>

#include <cstdio>

#define N 100005

using namespace std;



typedef long long ll;

ll n, x, m, sum, ans, c[N], s[N];

int main()
{

    ll i;

    cin >> n >> x >> m;

    for (i = 1; i <= n; i++, x = x * x % m) {

        if (!c[x]) c[x] = i, s[x] = sum;

        else break;

        sum += x;

    }

    if (i > n) {cout << sum << endl; return 0;}

    ll t = (n - c[x] + 1) / (i - c[x]);

    ans = s[x] + (sum - s[x]) * t;

    n = (n - c[x] + 1) % (i - c[x]);

    for (i = 1; i <= n; i++, x = x * x % m) {

        ans += x;

    }

    cout << ans << endl;

    return 0;

}

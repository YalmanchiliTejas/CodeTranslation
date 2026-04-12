#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    if (c*2 < a+b) {
        ll tmp = min(x, y);

        ll got = tmp * 2 * c;

        ll tmpnxt, prc;
        if (x > y) tmpnxt = x, prc = a;
        else tmpnxt = y, prc = b;

        ll got1st = got + ((tmpnxt - tmp) * prc);


        tmp = max(x, y);
        ll got2nd = tmp * 2 * c;

        cout << min(got1st, got2nd) << endl;
    }

    else {
        cout << (a * x) + (b * y) << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll req = 0;
    if (2*c < a+b) {
        req = 2 * min(x, y) * c;
        ll tmp = 2 * max(x, y) * c;

        if (x > y) req += a * (x-y);
        else req += b * (y-x);

        if (tmp < req) req = tmp;
    }


    else {
        req = x * a;
        req += y * b;
    }

     cout << req << "\n";
}

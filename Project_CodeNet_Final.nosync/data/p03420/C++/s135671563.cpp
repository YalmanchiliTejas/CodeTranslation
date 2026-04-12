#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll odp = 0;
    for (ll b = 1; b <= n; ++b)
    {
        ll c = n / b;
        ll r = n - c * b;
        if (k <= b - 1)
            odp += ((b - 1) - k + 1) * c;
        if (k <= r)
        {
            if (k != 0)
                odp += r - k + 1;
            else
                odp += r;
        }
    }
    cout << odp;
    return 0;
}

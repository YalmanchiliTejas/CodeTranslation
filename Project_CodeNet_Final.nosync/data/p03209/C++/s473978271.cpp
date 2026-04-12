#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> p(n + 1), b(n + 1);
    p[0] = 1;
    b[0] = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        p[i] = 2 * p[i - 1] + 1;
        b[i] = 2 + 2 * b[i - 1];
    }
    ll odp = 0, lev = n;
    while (true)
    {
        --x;
        if (x == 0)
            break;
        if (b[lev - 1] + p[lev - 1] <= x)
        {
            x -= b[lev - 1] + p[lev - 1];
            odp += p[lev - 1];
            if (x == 0)
                break;
        }
        else
        {
            --lev;
            continue;
        }
        --x;
        ++odp;
        if (x == 0)
            break;
        if (b[lev - 1] + p[lev - 1] <= x)
        {
            x -= b[lev - 1] + p[lev - 1];
            odp += p[lev - 1];
            if (x == 0)
                break;
        }
        else
        {
            --lev;
            continue;
        }
        --x;
        if (x == 0)
            break;
    }
    cout << odp;
    return 0;
}

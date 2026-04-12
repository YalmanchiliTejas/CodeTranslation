#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 60;

ll a[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n ; i ++ ) cin >> a[i];

    ll ans = 0;
    ll index;

    bool is = true;
    while(is)
    {
        ll maxs = 0;
        for (int i = 1; i <= n ; i ++ )
        {
            if(maxs < a[i])
            {
                maxs = a[i];
                index = i;
            }
        }

        if(maxs >= n)
        {
            ll x = maxs / n;
            ans += x;
            a[index] %= n;
            for (int i = 1; i <= n ; i ++ )
            {
                if(i != index) a[i] += x;
            }
        }
        else
        {
            is = false;
        }
    }

    cout << ans << endl;

    return 0;
}

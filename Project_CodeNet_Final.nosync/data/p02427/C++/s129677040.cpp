#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(n) (n).begin(), (n).end()

int main()
{
    ll n;

    cin >> n;

    for (ll bit = 0; bit < (1 << n); bit++)
    {
        vector<ll> sum;
        for (ll i = 0; i< n;i++) {
            if (bit & (1 <<i))
                sum.push_back(i);
        }

        cout << bit << ":";
        for (ll i = 0; i< (ll)(sum.size()); i++)
        {
            cout << " " << sum[i];
        }
        cout << endl;
    }


}

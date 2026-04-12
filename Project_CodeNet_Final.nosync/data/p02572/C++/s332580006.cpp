#include <bits/stdc++.h>
using namespace std;

#define read(a) cin >> a
#define out(a)  cout << a
#define ull unsigned long long
#define ll long long
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define fast ios_base::sync_with_stdio(0);

ll n;
ll tong = 0, kq = 0, x;
const ll mod = 1e9 + 7;

int main()
{
    fast;
    read(n);
    while(n--)
    {
        cin >> x;
        kq = (kq + (tong * x) % mod) % mod;
        tong =  (tong + x) % mod;
    }
    cout << (kq%mod + mod) % mod;
}

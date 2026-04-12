#include <iostream>
using namespace std;

#define ll long long
#define arrInput(arr, end)       \
    for (ll i = 0; i < end; i++) \
        cin >> arr[i];

#define MOD 1000000007

ll fastpow(ll a, ll n, ll m)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % m;
        n >>= 1;
        a = (a * a) % m;
    }
    return res;
}

ll add(ll a, ll b, ll m)
{
    return (a % m + b % m) % m;
}

ll sub(ll a, ll b, ll m)
{
    return ((a - b) % m + m) % m;
}

ll mul(ll a, ll b, ll m)
{
    return (a % m * b % m) % m;
}

ll div(ll a, ll b, ll m)
{
    return mul(a, fastpow(b, m - 2, m), m);
}

ll productSum(ll a[], ll n)
{
    ll arSum = 0;
    for (int i = 0; i < n; i++)
        arSum = add(arSum, a[i], MOD);

    ll arSumSq = mul(arSum, arSum, MOD);

    ll indSqSum = 0;
    for (int i = 0; i < n; i++)
        indSqSum = add(indSqSum, mul(a[i], a[i], MOD), MOD);

    return div(sub(arSumSq, indSqSum, MOD), 2, MOD);
}

int main()
{
    ll n;
    cin >> n;

    ll arr[n];
    arrInput(arr, n);

    cout << productSum(arr, n) << endl;

    return 0;
}

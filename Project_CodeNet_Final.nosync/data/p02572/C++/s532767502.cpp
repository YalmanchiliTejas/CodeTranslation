#include <iostream>

using namespace std;

#define MOD 1000000007
#define ll long long

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(ll b, ll m)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x%m + m) % m;
}

int
main(){
    int n;

    cin >> n;
    ll a[n];
    ll array_sum = 0, individual_square_sum = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        array_sum += a[i];
        array_sum %= MOD;

        individual_square_sum += (a[i]) * (a[i]);
        individual_square_sum %= MOD;
    }

    ll array_sum_square = (array_sum) * (array_sum);

    ll ac = (array_sum_square - individual_square_sum) % MOD;
    ll inv = modInverse(2, MOD);

    cout << ((inv * ac) % MOD) << endl;

    return 0;
}

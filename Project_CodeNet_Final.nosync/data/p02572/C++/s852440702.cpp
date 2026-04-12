#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define s(x, n) memset(x, n, sizeof(x));
#define pb(x) push_back(x)

ll findProductSum(ll A[], ll n)
{
    ll array_sum = 0;
    for (ll i = 0; i < n; i++)
    {
        array_sum = (array_sum % mod) + (A[i] % mod);
        array_sum %= mod;
    }

    ll array_sum_square = (array_sum * array_sum) % mod;

    ll individual_square_sum = 0;
    for (ll i = 0; i < n; i++)
    {
        individual_square_sum += (A[i] * A[i]) % mod;
        individual_square_sum %= mod;
    }

    return ((array_sum_square - individual_square_sum + mod) % mod * 500000004) % mod;
}
int main()
{
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef WIN32
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findProductSum(arr, n) % mod << "\n";
    return 0;
}
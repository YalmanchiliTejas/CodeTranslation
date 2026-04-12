#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    ll n;

    cin >> n;

    ll arr[n];

    ll arr1[n];

    ll mod = 1e9+7;

    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
        arr1[i] = arr[i];
    }

    for(ll i=1; i<n; i++)
    {
        arr1[i] = (arr1[i] + arr1[i-1]) % mod;

    }

    ll z = arr1[n-1];

    ll sum = 0;



    for(ll i=0; i<n-1; i++)
    {
        ll temp = (z - arr1[i]) % mod;

        if(temp < 0)
        {
            temp += mod;
        }

        temp = (temp * arr[i]) % mod;

        sum = (sum + temp) % mod;
    }

    cout << sum % mod;



}


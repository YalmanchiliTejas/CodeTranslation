#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mod = 1000000007;
ll arr[200005];
ll sum[200005];

void prefix(int n)
{
    sum[0] = arr[0] % mod;
    for(int i = 1; i < n; i++)
    {
        sum[i] = (sum[i - 1] + arr[i]) % mod;
    }
}

int main()
{
    fast_in_out;
    int n;
    cin >> n;
    ll s = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    prefix(n);
    for(int i = 0; i < n; i++)
    {
        ll x = (sum[n - 1] - sum[i]) % mod;
        if(x < 0)
        {
            x += mod;
        }
        ll y = arr[i] % mod;
        ll z = (x * y) % mod;
        s += z;
        s %= mod;
    }
    cout << s;
}

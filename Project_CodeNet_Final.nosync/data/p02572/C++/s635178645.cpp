#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main()
{
    int n;
    cin>>n;
    ll a[200005];
    ll sum = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum %= mod;
    for(int i = 0; i < n-1; i++){
        sum -= a[i];
        sum = (sum + mod) % mod;
        ans += sum * a[i];
        ans %= mod;
    }
    cout<<ans;
    return 0;
}

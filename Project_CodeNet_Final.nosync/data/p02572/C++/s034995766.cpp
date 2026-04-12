#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define set_bits(a) __builtin_popcount(a)
#define pb push_back
#define pf push_front
#define mod 1000000007
#define M 998244353
#define mp unordered_map
#define fi first
#define se second
#define endl '\n'
#define INF 1e18
#define PI 3.14159265358979323846
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    ll n,i,j;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll suff[n];
    ll sum=0;

    for(i=n-1;i>=0;i--)
    {
        sum = (sum%mod + arr[i]%mod)%mod;
        suff[i] = sum;
    }

    ll ans=0;

    for(i=0;i<n-1;i++)
    {
        ll x = (arr[i]%mod * suff[i+1]%mod)%mod;
        ans = (ans%mod + x%mod)%mod;
    }

    cout<<ans<<endl;
}

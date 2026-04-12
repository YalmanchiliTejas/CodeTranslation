#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> pref(n);
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    ll sum=0;
    for(ll i=n-1;i>=0;i--)
    {
        sum+=arr[i];
        pref[i]=sum;
    }
    ll ans=0;
    ll p=1000000007;
    for(ll i=0;i<n;i++)
    {
        ans+=((pref[i]-arr[i])%p *(arr[i]))%p;
        ans%=p;

    }
    cout << (ans%p);
}

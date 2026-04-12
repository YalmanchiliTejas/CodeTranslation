#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<ll> suff(n);
    suff[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suff[i] = (suff[i+1] + arr[i])%mod;
    }
    long long ans = 0;
    for(int i=0;i<n-1;i++)
    {
        ans = (ans + (arr[i]*suff[i+1])%mod)%mod;
    }
    cout<<ans;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define p 1000000007
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        sum=(sum%p+a[i]%p)%p;
    }
   // cout<<sum<<endl;
    ll prod=0;
    ll prev=0;
    for(ll i=0;i<n;i++)
    {
        prev=(prev%p+a[i]%p)%p;
        
        prod=((prod%p+(((sum%p-prev%p+p)%p)*a[i]%p)%p))%p;
    }
    cout<<prod<<endl;
}
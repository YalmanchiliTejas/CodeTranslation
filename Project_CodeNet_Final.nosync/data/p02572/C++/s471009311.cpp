#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    long long n;
    const unsigned int m= 1000000007;
    cin>>n;
    ll sum=0,ans=0;
    ll arr[n];
    for( ll i=0;i<n;i++)
       {
           cin>>arr[i];
        arr[i]=arr[i];
        sum=sum+arr[i];
       }
    for(ll i=0;i<n;i++)
    {
        int s=(sum-arr[i])%m;
        ans = (ans + (s*arr[i]))%m;
        sum=sum-arr[i];

    }
    cout<<ans%m;


}


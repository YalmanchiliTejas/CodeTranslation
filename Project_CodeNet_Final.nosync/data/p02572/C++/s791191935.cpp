#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main()
{
    long long n,sum=0;
    cin>>n;

    long long ar[n];

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
        sum%=mod;
    }

    long long ans=0;

    for(int i=0;i<n;i++)
    {
        sum-=ar[i];
        sum+=mod;
        sum%=mod;
        ans+=ar[i]*(sum+mod);
        ans%=mod;
    }

    cout<<ans;


}
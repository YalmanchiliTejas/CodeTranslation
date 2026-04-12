#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    long long int a[n],pref[n];
    for(long int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i)
        pref[i]=a[i]+pref[i-1];
        else
        pref[i]=a[i];
    }
    long long int ans=0, m=1e9+7;
    for(long int i=0;i<n;i++)
    {
        ans=(ans + (a[i]*((pref[n-1]-pref[i])%m))%m)%m;
    }
    cout<<ans<<endl;
}
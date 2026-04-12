#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,j,k=0,mod=1e9+7;
    cin>>n;
    vector<long long> a(n),pref(n+1);
    pref[0]=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        pref[i+1]=pref[i]+a[i];
        pref[i+1]%=mod;
    }
    for(i=n-1;i>0;i--)
    {
        //cout<<a[i]<<" "<<pref[i-1]<<'\n';
        k=(k+(a[i]*pref[i])%mod)%mod;
    }
    cout<<k<<'\n';
  return 0;
}

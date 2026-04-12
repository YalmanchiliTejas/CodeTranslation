#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    int n,i,s=0,mod=1000000007;
    cin>>n;
    int a[n],res=0;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=n-1;i>=0;i--)
    {
        res+=a[i]*s;
        s+=a[i];
        res%=mod;
        s%=mod;
    }
    cout<<res<<endl;
}

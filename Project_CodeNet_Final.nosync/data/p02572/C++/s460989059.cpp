#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int $=1;
    ll MOD=1e9+7;
    //cin>>$;
    while($--)
    {
        ll n,ans=0,i;
        cin>>n;
        ll a[n],b[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            a[i]%=MOD;
        }
        b[n-1]=a[n-1];
        for(i=n-2; i>=0; i--)
            b[i]=(b[i+1]+a[i])%MOD;

        for(i=0; i<n-1; i++)
        {
            ans+=(b[i+1]*a[i])%MOD;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
}


/*
8888888888888888888888888888
    Md. Masud Mazumder
    University of Chittagong
    Department of CSE
8888888888888888888888888888
*/

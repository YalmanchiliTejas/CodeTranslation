#include<bits/stdc++.h>
#define int long long
using namespace std;

long long power(long long a, long long b,long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}


int pre[200005];
const int mod=1e9+7;

signed main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif      

    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int z=(pre[n]-pre[i]+mod)%mod;
        ans+=(z*a[i])%mod;
        ans%=mod;
    }
    cout<<ans;

}
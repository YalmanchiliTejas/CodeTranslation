/*
   Username : moondancer
   Name : Moon Dancer
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n],s[n];
    int m=1e9+7;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        s[i]=a[i];
        if(i)
            s[i]=(s[i]+s[i-1])%m;
    }
    int ans=0;
    for (int i = 1; i < n; ++i)
    {
        ans=(ans+(s[i-1]*a[i])%m)%m;
    }
    cout<<ans;
    return 0;
}
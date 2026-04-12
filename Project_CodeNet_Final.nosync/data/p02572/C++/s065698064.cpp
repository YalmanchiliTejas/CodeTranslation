//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int mod=1e9+7;
int n;
int inv(int x)
{
    int r,y;
    for(r=1,y=mod-2;y>0;x=(x*x)%mod,y/=2)
        if(y%2==1)
            r=r*x%mod;
    return r;
}
int32_t main()
{
    IOS;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sum%=mod;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int val=(sum-arr[i]+5*mod)%mod;
        int curr=(val*arr[i])%mod;
        ans=(ans+curr)%mod;
    }
    ans=(ans*inv(2))%mod;
    print(ans);
}

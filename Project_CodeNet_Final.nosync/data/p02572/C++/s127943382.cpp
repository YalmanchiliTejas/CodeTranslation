#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
  	ll m=1000000000+7;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        ans+=((a[i]%m)*(sum%m))%m;
    }
    cout<<ans%m;
}
int main()
{
    solve();
    return 0;
}
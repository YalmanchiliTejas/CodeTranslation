#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
#include <fstream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--) {
    ll ans=0,i,j,n;
    cin>>n;
    ll arr[n+1];
    for(i=0;i<n;i++)
        cin>>arr[i];
    ll dp[n+1];
    dp[0]=arr[0];
    for(i=1;i<n;i++)
        dp[i]=(dp[i-1]+arr[i])%hell;
    for(i=1;i<n;i++)
        ans=(ans+(arr[i]*dp[i-1])%hell)%hell;
    cout<<ans;
}
}

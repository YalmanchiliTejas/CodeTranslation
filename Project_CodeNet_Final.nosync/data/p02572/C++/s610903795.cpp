#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int suff[n+1]={};
    for(int i=n-1;i>=0;i--)
    {
        suff[i]=suff[i+1]+arr[i];
    }
    int ans=0;
    int mod=pow(10,9)+7;
    for(int i=0;i<n;i++)
    {
        int x=suff[i+1];
        x%=mod;
        arr[i]*=x;
        arr[i]%=mod;
        ans+=arr[i];
        ans%=mod;
    }
    cout<<ans<<endl;
}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
    return 0;
}

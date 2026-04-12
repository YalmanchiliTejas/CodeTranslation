#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long arr[N];
long long cum[N];
int mod=1000000007;
int solve()
{
    int n;
    cin>>n;
    long long ans=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cum[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
        cum[i]=(arr[i]+cum[i+1])%mod;
   /* for(int i=0;i<n;i++)
        cout<<cum[i]<<" ";*/
    for(int i=0;i<n-1;i++)
        ans=(ans+arr[i]*cum[i+1])%mod;
    cout<<ans;
    return 0;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt" ,"r" ,stdin);
    freopen("output.txt" ,"w" ,stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin>>t;
    // while(t--)
    solve();

    return 0;
}
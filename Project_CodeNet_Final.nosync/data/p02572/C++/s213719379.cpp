#include<bits/stdc++.h>
using namespace std;
#include <numeric> 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define int long long int
#define mod 1000000007
#define INT_BITS 16
#define test int t;cin>>t;while(t--)
#define INF 10000000
#define pi 3.141592
#define watch(x) cout<<(#x)<<"="<<(x)<<"\n" 
#define pb push_back
//#include "debug.cpp"
//__builtin_popcount

int32_t main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        /* code */
    }

    int sum[n]={0};
    sum[0]=a[0]%mod;
    for(int i=1;i<n;i++)
    {
        sum[i]=(sum[i-1]+a[i])%mod;
    }

    int ans=0;
    int val=sum[n-1];
    //watch(val);
    for (int i = 0; i <n-1; ++i)
    {
        ans=(ans+((val-sum[i])*a[i])%mod)%mod;
        //ans=(ans+(ans*a[i])%mod)%mod;
        // watch(sum[i]);
        // watch(ans);
    }
    if(ans<0)
        ans+=mod;
    cout<<ans<<endl;

}

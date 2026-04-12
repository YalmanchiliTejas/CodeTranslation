#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
#define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
const int mod=1000000007;
const int INF=1e18;
int a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum=0;
    cin>>n;
    f(i,0,n) {
        cin>>a[i];
        sum+=a[i];   
    }
    sum%=mod;
    int ans=0;
    f(i,0,n) {
        sum-=a[i];
        sum+=mod;
        sum%=mod;
        ans=(ans+a[i]*sum)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
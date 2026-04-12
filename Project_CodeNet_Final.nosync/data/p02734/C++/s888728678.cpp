#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define int long long
const int MOD=998244353;
const int N=1e5+5;

int gcd(int n,int m)
{
    if(n==0)
        return m;
    else
        return gcd(m%n,n);
}
int n,s;
int dp[3005][3005];
int a[3005];
int go(int pos,int sum)
{
    if(sum==s)
        return n-pos+2;
    if(sum>s)
        return 0;
    if(pos==n+1)
        return 0;
    int &ans=dp[pos][sum];
    if(ans!=-1)
        return ans;
    ans=0;
    ans+=go(pos+1,sum);
    ans+=go(pos+1,sum+a[pos]);
    ans%=MOD;
    return ans;
}
int32_t main()
{
    IOS;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    int sum=0;
    for(int i=1;i<=n;i++)
    {

        sum+=go(i,0);
        sum%=MOD;
    }
    cout<<sum<<endl;




    
    
 
 
    
 
 
    
    
}
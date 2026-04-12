#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define vi  vector<int>
#define vii vector<pair<int,int>>
#define vll vector<lli>
#define pb  push_back
#define mp  make_pair
#define ss  second
#define ff  first
#define all(x) x.begin(),x.end()
const lli mod = 1000000007;

lli p2(lli n){lli ans=0;while(n>=1){n=n/2;ans++;}return ans;}
lli b_ex(lli n,lli a){lli res=1;while(n){if(n%2==1)res*=a;n>>=1;a=a*a;}return res;}
lli ncr(lli n,lli k){lli ans=1;if(k>n-k)k=n-k;for(lli i=1;i<=k;i++){ans*=(n-i+1),ans=ans/i;}return ans;}
lli add(lli a,lli b){return(a+b)%mod;}
lli mul(lli a,lli b){return (a*b)%mod;}
lli power(lli a , lli n){lli ans = 1;while(n){if(n % 2)ans = (ans * a) % mod;n /= 2;a = (a * a) % mod;}return ans;}
lli lcm(lli a,lli b)
{
    lli ans=(a*b)/(__gcd(a,b));
    return ans;
}
///------------------ALWAYS lli-----TEMP TSF99--------------------------------------------------------------------------------------///
const int inf=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>order(n),fuel(n);
    int mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>order[i];
        mx=max(order[i],mx);
    }
    for(int i=0;i<n;i++)cin>>fuel[i];
    lli dp[2*mx+1];
    for(int i=0;i<2*mx+1;i++)dp[i]=inf;
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=fuel[i];j<2*mx+1;j++)
        {
            if(dp[j]>dp[j-fuel[i]]+1)dp[j]=dp[j-fuel[i]]+1;
        }
    }
    lli res=0;
    for(int i=0;i<n;i++)
    {
        res+=dp[2*order[i]];
    }
    cout<<res<<endl;
}
int main()
{
    int x;cin>>x;
    if(x<30)cout<<"No\n";
    else cout<<"Yes\n";
}

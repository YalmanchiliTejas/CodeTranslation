#include <bits/stdc++.h>
   
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define deb(x) cout << #x << "=" << x << endl
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define vi vector<int>
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<endl
#define mod 998244353
#define int long long



const int N=3005;
int a[N];
int dp[N][N];
int n;

int solve(int ind,int sum)
{
    //cout<<"here\n";
    if(sum==0)
    {
        return (n-ind+2);
    }
    
    if(sum<0)
    {
        
        return 0;
    }
    
    if(ind>n)
    { 
        //cout<<ind<<" "<<n<<endl;
        return 0;
    }
    
    if(dp[ind][sum]!=-1)
    {
        
        return dp[ind][sum];
    }
   
    int ans=0;
    
    int op1=solve(ind+1,sum);
   // deb(op1);
   
    int op2=solve(ind+1,sum-a[ind]);
     //deb(op2);
    ans=op1+op2;
    ans%=mod;
    dp[ind][sum]=ans;
    
    return ans;
    
}

int32_t main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sum;
    cin>>n>>sum;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=solve(i,sum);
       // deb(ans);
    }
    cout<<ans%mod;
}
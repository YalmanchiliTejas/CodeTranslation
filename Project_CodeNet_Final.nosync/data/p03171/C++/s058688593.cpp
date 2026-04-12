#include<bits/stdc++.h>
using namespace std;

const long long mod =1e9+7 ;
const int N = 3e3+5;


#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define fr(i,l,m) for(int i=l;i<m;i++)
# define vii vector<int>
#define vpr vector<pair<int,int> >
#define dbg(x) cout << #x << " is " << x << endl;
#define spk(x) cout<<x<<endl;
ll pwr(ll x,ll y);

////
////
////
ll a[3005], n,dp[N][N];
ll ans=0;
ll solve(ll l,ll r)
{

    if(l>r)return 0;
    int sz=(r-l+1);
    if(dp[l][r]!=mod)return dp[l][r];
    if((n-sz)%2)
    {
        if(l==r){dp[l][r]=-1*(ll)a[l];return -1*(ll)a[l];}
    dp[l][r]= min(-1*a[l]+(dp[l+1][r]==mod?solve(l+1,r):dp[l+1][r]),-1*a[r]+(dp[l][r]==mod?solve(l,r-1):dp[l][r-1]));
        //dbg(p);
        return dp[l][r];

    }
    else
    {
        if(l==r){dp[l][r]=a[l];return (ll)a[l];}
         dp[l][r]= max(a[l]+(dp[l+1][r]==mod?solve(l+1,r):dp[l+1][r]),a[r]+(dp[l][r-1]==mod?solve(l,r-1):dp[l][r-1]));
         //dbg(p)
         return dp[l][r];
    }
}
////
////
///
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

cin>>n;

fr(i,1,n+1)
{
    cin>>a[i];
}
fr(i,0,n+1)
{
    fr(j,0,n+1)
    {

        dp[i][j]=mod;
    }
}
cout<<solve(1LL,n)<<endl;
return 0;

 }
ll pwr(ll x,ll y)
{
    ll ans=1;
    x=x%mod;
    while(y>0){
    if(y&1)ans=(x*(ans%mod))%mod;
    x=(x*x)%mod;
    y=y/2;

    }
    return ans%mod;
}

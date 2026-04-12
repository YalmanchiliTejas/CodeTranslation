#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqb             priority_queue<ll>
#define pqs             priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            ll x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mx 3000
ll n,m;
ll dp[3005][3005][2];
ll a[3005];
vector<ll>v;

ll solve(ll i,ll j,bool k){
    if(i>j)return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(k==1)
        return dp[i][j][k]=max(a[i]+solve(i+1,j,0),a[j]+solve(i,j-1,0));
    else return dp[i][j][k]=min(solve(i+1,j,1),solve(i,j-1,1));

}
int main()
{
    FIO;
    ll c,d,e,f=0,sum=0,ck,k,p,q,r,t,add=0,w,x,y,z;
    cin>>n;
        for(int i=0;i<n;i++) {cin>>a[i];sum+=a[i];}
        memset(dp,-1,sizeof dp);
        x=solve(0,n-1,1);
        y=sum-x;
        ll ans=x-y;
        cout<<ans<<endl;


    return 0;
}

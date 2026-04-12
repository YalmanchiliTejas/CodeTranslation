#include<bits/stdc++.h>
using namespace std;

void input()
{ 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
}
#define endl "\n"
#define ll long long int
#define vll vector<ll>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define ff first
#define ss second
#define tll tuple<ll,ll,ll>
#define mt make_tuple
#define INF LONG_LONG_MAX
#define mod 1000000007
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define cases ll t; cin>>t; while(t--)
#define array(a,n) ll a[n]; rep(i,0,n) cin>>a[i];
#define vector(a,n) vll a(n); rep(i,0,n) cin>>a[i];
#define sortall(a) sort(a.begin(),a.end())
#define printall(a,n) rep(i,0,n) cout<<a[i]<<" "; cout<<endl;

// --------------- My Template End --------------- //


int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    //input();
    ll n,sum=0,diff=0;
    cin>>n;
    vector(a,n);
    vector <vector<ll>>dp(n,vector<ll>(n,0));
    rep(i,0,n){sum+=a[i];dp[i][i]=a[i];}
    
   rep(gap,2,n+1)
   {
    rep(i,0,n-gap+1)
    {
        int j=i+gap-1;
        if(j==i+1)dp[i][j]=max(a[i],a[j]);
        else{
                dp[i][j]=max(a[i]+min(dp[i+1][j-1],dp[i+2][j]),a[j]+min(dp[i][j-2],dp[i+1][j-1]));
            }
       
        }      
    }
    
    
    cout<<2*dp[0][n-1]-sum;
}

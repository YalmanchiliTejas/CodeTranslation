#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define nt _int128
#define mod 1000000007
# define ppi pair<ll,ll>
ll n,arr[3005],cnt[3005]={0};
vector<vector<vector<ppi>>>dp(3005,vector<vector<ppi>>(3005,vector<ppi>(2)));
ppi func(ll chan,ll i,ll j)
{
    if(i>j)
        return {0,0};
    ppi u=dp[i][j][chan];
    if(u.first!=-1 and u.second!=-1)
        return dp[i][j][chan];
    ppi x=func(1-chan,i+1,j);
    ppi y=func(1-chan,i,j-1);
    if(chan)
    {    
        if(arr[i]+x.first-x.second>=arr[j]+y.first-y.second)
            dp[i][j][chan]={x.first+arr[i],x.second};
        else
            dp[i][j][chan]={y.first+arr[j],y.second};
    }
    else
    {
        if(x.first-x.second-arr[i]<=y.first-y.second-arr[j])
            dp[i][j][chan]={x.first,x.second+arr[i]};
        else
            dp[i][j][chan]={y.first,y.second+arr[j]};
    }
    return dp[i][j][chan];
}
int main()
{
// #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t  = 1;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<3005;i++)
        {
            for(ll j=0;j<3005;j++)
            {
                for(ll k=0;k<2;k++)
                    dp[i][j][k]={-1,-1};
            }
        }
        for(ll i=1;i<=n;i++)
        {
            cin>>arr[i];
            cnt[i]=cnt[i-1]+arr[i];
        }
        ppi d=func(1,1,n);
        cout<<d.first-d.second;
    }
    return 0;
}
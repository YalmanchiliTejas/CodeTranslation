/*            AUTHOR - SHIVAM GUPTA
                       Jalpaiguri Govt. Engg College             */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll> ve[100005];
ll dp[3005][3005],z;
ll a[3005]={0};
const ll inf=-1e18;

ll memo(ll l, ll r)
{
    if(l==r)
    return a[l];
    if(dp[l][r]!=inf)
    return dp[l][r];
    dp[l][r]=max( a[l]-memo(l+1,r), a[r]-memo(l,r-1) );
    return dp[l][r];
}

void solve()
{
    vector<ll> v;        vector<pair <ll,ll>> vp;
    map<ll,ll> mp;       set<ll> st;        multiset<ll> mst;
    ll n=0,m=0,i=0,j=0,k=0,c=0,l=0,r=0,p=0,q=0,x=0,y=0,z=0,flag=0,sum=0;
    
    string s,t;
    cin>>n;
    for(i=0;i<n+4;i++)
        for(j=0;j<n+4;j++)
            dp[i][j]=inf;
    for(i=1;i<=n;i++)
    cin>>a[i];
    cout<<memo(1,n)<<endl;
    
}
bool imp=false;int main()
{
    fio;
    int t=1;
    if(imp)
	cin>>t;
	ll j=t;
    while(t--){
    // cout<<"Case #"<<j-t<<": ";
    solve();}
    return 0;
}
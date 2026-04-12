#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define debug(x) cerr<<#x<<" "<<x<<endl;
#define f(i,n) for(ll i=0; i<n; i++)
#define f1(i,n) for(ll i=1; i<=n; i++)
#define fr(i,n) for(ll i=n-1; i>=0; i--)
#define f1r(i,n) for(ll i=n; i>0; i--)
#define mst(arr,val) memset(arr,val,sizeof(arr))
#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef pair<ll,ll> pii;
ll M=1e9+7;
ll M2=998244353;
void show(vector<ll> v)
{
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}
void showrev(vector<ll> v)
{
    for(int i=0; i<v.size(); i++)
        cout<<v[v.size()-i-1]<<" ";
    cout<<"\n";
}
void showarr(ll arr[],ll n)
{
    for(ll i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
void showpv(vector<pair<ll,ll> > v)
{
    f(i,v.size())
        cout<<"("<<v[i].ff<<","<<v[i].ss<<")"<<" ";
    cout<<"\n";
}
void showmap(map<ll,ll> m)
{
    for(auto i:m)
        cout<<" ("<<i.ff<<","<<i.ss<<") ";
    cout<<"\n";
}
int main()
{
    IOS
    ll T = 1,Q=1;
    //cin>>T;

    while(T--)
    {
        ll n;   cin>>n;
        ll a[n+1];
        f(i,n)
            cin>>a[i+1];
        ll dp[n+1][n+1];    mst(dp,0);
        f1(i,n)
            dp[i][i] = a[i];
        f1(len,n-1)
        {
            for(ll i=1; i+len<=n; i++)
            {
                ll j=i+len;
                dp[i][j] = max(a[j]-dp[i][j-1],a[i]-dp[i+1][j]);
            }
        }
        cout<<dp[1][n];
    }
    return 0;
}

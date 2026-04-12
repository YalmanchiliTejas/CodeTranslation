#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
const int N=100005;
ll mod = 1e9+7;
ll a[2*N];
void solve()
{
    ll n,m=0,k=0,i=1,j,p,f,x, y, z;
    ll ans=0,sum=0;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++)
    {
        ans+=(a[i]*sum)%mod;
        sum+=a[i];
        sum%=mod;
        ans%=mod;
    }
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif 
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
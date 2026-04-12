#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using llu=unsigned long long;
#define mod 1000000007
#define mode 998244353
#define PI 3.14159265358979323846
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mms(x,y) memset(x,y,sizeof(x))
#define pqm priority_queue<ll,vector<ll>,greater<ll>>
#define pb push_back
#define um unordered_map
#define pr pair
#define mm multimap
#define ms multiset
#define mp make_pair
#define vr vector
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define inf INT_MAX
#define ninf INT_MIN
#define ff first
#define ss second
#define gcd __gcd
ll dp[3005][3005];
ll rohan(ll i,ll j,ll *a)
{
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll l=min(rohan(i+2,j,a),rohan(i+1,j-1,a));
    ll r=min(rohan(i,j-2,a),rohan(i+1,j-1,a));
    return dp[i][j]=max(l+a[i],r+a[j]);
}
int main()
{
    fast;
    ll t,n,m,i,j,k;
    cin>>n;
    ll a[n];
    mms(dp,-1);
    k=0;
    for(i=0;i<n;i++)cin>>a[i],k+=a[i];
    cout<<2*rohan(0,n-1,a)-k;
}

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ll long long
#define dd double
#define MOD1 1000000007
#define MOD2 998244353
#define nl cout<<endl
#define rt ll Q[100005]={0}
#define mp make_pair
#define test() ll t;cin>>t;while(t--)
#define pb push_back
#define ff first    
#define ss second
#define all(v) v.begin(),v.end()
#define s(ar,n) sort(ar,ar+n)
#define rs(ar,n) sort(ar, ar+n, greater<ll>()) 
#define oa(a,n) for(ll i=0;i<n;i++)cout<<a[i]<<" ";nl
#define cn(a,n) for(ll i=0;i<n;i++)cin>>a[i];
#define ov(a,n) for(ll i=n-1;i>=0;i--)cout<<a[i]<<" ";nl
#define ovp(a,n) for(ll i=0;i<n;i++)cout<<a[i].ff<<" "<<a[i].ss<<endl;
#define maxa(ar,N) *max_element(ar,ar+N)
#define mina(ar,N) *min_element(ar,ar+N)
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<ll,ll> pii;
ll powe(ll n,ll m){if(m==0)return 1;ll t=powe(n,m/2);if(m%2==0)return (t*t);return (((t*t))*n);}
ll mpowe(ll n,ll m,ll MOD){if(m==0)return 1;ll t=mpowe(n,m/2,MOD);t%=MOD;if(m%2==0)return (t*t)%MOD;return (((t*t)%MOD)*n)%MOD;}
ll logtwo(ll n){if(n==1)return 0;if(n==0) return -1;return logtwo(n/2)+1;}
int main()
{
    fastio();
   
    int n;
    cin>>n;
    ll a[n];
    cn(a,n);
    ll dp[n]={0};
    dp[0]=a[0];
    for(int i=1;i<n;i++)
        dp[i] =(dp[i-1]+a[i])%MOD1;
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ll d = a[i]*dp[i-1];
        d%=MOD1;
        ans+=d;
        ans%=MOD1;
    }
    cout<<ans<<endl;
}
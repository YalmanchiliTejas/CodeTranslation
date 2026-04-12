#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ll long long
#define dd double
#define MOD 1000000007
#define nl cout<<endl
#define rt ll Q[100005]={0}
#define mp make_pair
#define test() ull t;cin>>t;while(t--)
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
typedef pair<int,int> pii;
ll powe(ll n,ll m){if(m==0)return 1;ll t=powe(n,m/2);if(m%2==0)return (t*t);return (((t*t))*n);}
ll mpowe(ll n,ll m){if(m==0)return 1;ll t=mpowe(n,m/2);t%=MOD;if(m%2==0)return (t*t)%MOD;return (((t*t)%MOD)*n)%MOD;}
ll logtwo(ll n){if(n==1)return 0;return logtwo(n/2)+1;}

int main()
{
    fastio();
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    ll n,m;
    cin>>n>>m;
    if(n==m)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
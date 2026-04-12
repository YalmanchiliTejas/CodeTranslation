#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define LONGMAX 1e18
#define ll long long
#define dd double
#define MOD 1000000007
#define nl cout<<endl
#define rt ll Q[100005]={0}
#define mp make_pair
#define endl "\n"
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
#define maxa(ar,N) *max_element(ar,ar+N)
#define mina(ar,N) *min_element(ar,ar+N)
#define INF 1e9
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
ll powe(ll x,ll y){ll res=1;while(y>0){if(y&1)res=res*x;y=y>>1;x=x*x;}return res;}
ll mpowe(ll n,ll m){if(m==0)return 1;ll t=powe(n,m/2);t%=MOD;if(m%2==0)return (t*t)%MOD;return (((t*t)%MOD)*n)%MOD;}
ll logtwo(ll n){if(n==1)return 0;return logtwo(n/2)+1;}
void ceilsearch(ll ar[],ll low,ll high,ll x,ll &y){ll mid=(low+high)/2;if(low>high)return;if(ar[mid]>=x){y=mid;ceilsearch(ar,low,mid-1,x,y);}else{ceilsearch(ar,mid+1,high,x,y);}}
int main()
{
	fastio();
	ll N,M;
	cin>>N>>M;
	if(N==M)
	    cout<<"Yes";
	   else
	   cout<<"No";
}
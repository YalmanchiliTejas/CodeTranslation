#include<bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll long long 
#define ull long
#define mpa make_pair
#define pb push_back
#define ff first
#define pii pair<ll,ll>
#define dd long long
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
#define fre freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
using namespace std;
ll a[200005];
ll suff[200005];
int main(){
	ll n,m;
	ll mod=1e9+7;
	ll ans=0;
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=n;i>=1;i--)suff[i]=(suff[i+1]+a[i])%mod;;
	
	for(ll i=1;i<=n;i++){
	   ans=ans+(a[i]*suff[i+1])%mod;
	   ans%=mod;
	}
	cout<<ans;
}
  
  
  
   


    
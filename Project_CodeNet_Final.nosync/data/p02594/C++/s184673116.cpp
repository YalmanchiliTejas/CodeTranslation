#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp make_pair
#define pb push_back
#define fp first
#define sp second
typedef long long int ll;
typedef pair<ll,ll> pp;
#define check(x, i) ((x>>i)&1LL)
#define set(x,i) (x|(1LL<<i))
#define unset(x,i) (x&~(1LL<<i))
#define INF LONG_MAX
#define MAX_N 20
#define MAX 4000005
#define mod 1000000007
#define REP(i,n) for(i=0;i<n;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define len(i,s) for(i=0;s[i];i++)
#define T() ll t;cin>>t;while(t--)
ll gcd (ll a, ll b){return (a?gcd(b%a,a):b);}
ll pow1(ll a,ll b,ll MOD){ll ans=1;while(b!=0){if(b&1)ans=(ans*a)%MOD;a=(a*a)%MOD;b=b/2;}return ans;}
ll modInverse(ll a,ll p){return pow1(a,p-2,p);}


int main()
{	
  boost
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);    
    freopen("output.txt", "w", stdout);
#endif
ll n;
cin>>n;
if(n>=30)
	cout<<"Yes\n";
else
	cout<<"No\n";
}
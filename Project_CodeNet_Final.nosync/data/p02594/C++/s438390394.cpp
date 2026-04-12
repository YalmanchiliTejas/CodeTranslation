#include<bits/stdc++.h>
#define mod 1000000007
#define INF 1000000000000000005
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define vc vector
#define vll vector<long long>
#define pll pair<long long,long long> 
#define pb push_back
#define all(v) v.begin(),v.end()
#define T ll test;cin>>test; while(test--)
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define MAX 1000005
#define sz(x) (ll)x.size()
#define ins insert
#define mp make_pair
#define int  long long
typedef  long long ll;
typedef long double ld;
using namespace std;

inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a,int b){return (a*1ll*b)%mod;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int inv(int a){return power(a,mod-2);}

signed  main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll n;
	cin>>n;
	if(n>=30) cout<<"Yes\n";
	else cout<<"No\n";
}
   
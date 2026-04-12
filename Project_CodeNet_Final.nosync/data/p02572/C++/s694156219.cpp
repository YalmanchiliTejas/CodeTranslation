#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;

#define sync std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define loopi(n) for(int i=0;i<n;i++)
#define loopj(n) for(int j=0;j<n;j++)
#define loop(a,b,c) for(int i=a;i<=b;i=i+c)

#define     deb(x)      cout<<#x<<"="<<x<<endl
#define     all(x)      (x).begin(),(x).end()
#define     reset(a)    memset(a,0,sizeof(a))
#define     sz(x)       ((int)(x.size()))
#define     pb          push_back
#define     pf          push_front
#define     pob	        pop_back
#define     pof         pop_front
#define     ins         insert
#define     F           first
#define     S           second
#define     mkp         make_pair
#define     mkt         make_tuple
#define     bitcount(x) __builtin_popcountll(x)
#define     gcd(a,b)    (__gcd(a,b))
#define     lcm(a,b)    ((a*b)/gcd(a,b))
#define PI 3.1415926535897932384626
 
const int mod = 1e9+7;

//============================================//

void solve()
{
	int n;
	cin>>n;
	ll a[n];
	loopi(n)	cin>>a[i];
	
	ll ans=0,sum=0;
	loopi(n)
		sum=sum+a[i];
		
	loopi(n-1)
	{
		sum=sum-a[i];
		ans=(ans%mod+((a[i]%mod)*(sum%mod))%mod)%mod;
	}
	cout<<ans;
}
int main() 
{
	sync;

	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
		cout<<endl;
	}
}
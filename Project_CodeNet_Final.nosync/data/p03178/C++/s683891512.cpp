//rohitaas_15
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#define co(x) 						          cout<<x<<"\n";
#define ld 							            long double
#define ll                          long long
#define int                         ll
#define dd                          double
#define rohitaas_15();              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) 											v.begin(),v.end()
#define f(a,b) 											for(int i=a;i<=b;i++)
#define f2(a,b) 										for(int j=a;j<=b;j++)
#define f3(a,b) 										for(int kk=a;kk<=b;kk++)
#define print2D(x) 									for(auto i : (x)){for(auto j : i){cout<<j<<" ";}nl;}nl;
#define pb 													push_back
#define mp 													make_pair
#define pii													pair<ll,ll>
#define ff 													first
#define ss 													second
#define nl 													cout<<"\n"
#define lb(v,x) 										lower_bound(v.begin(),v.end(),x)
#define ub(v,x) 										upper_bound(v.begin(),v.end(),x)
#define pv(v,x,n) 									if(n!=0){f(x,n-1){cout<<v[i]<<" ";}cout<<endl;}
#define cn(v,x,n) 									f(x,n){cin>>v[i];}
#define M1 													1000000007
#define M2	 												998244353
#define con 												continue
#define maxv(v) 										*max_element(all(v));
#define minv(v) 										*min_element(all(v));
#define sumv(v) 										accumulate(all(v),0ll)
#define pf 													push_front
#define popb 												pop_back
#define popf 												pop_front
#define br 													break
#define rev(x)  										reverse(all(x))
#define vr 													vector<ll>
#define vvr													vector<vr>
#define vvvr 												vector<vvr>
#define vll 												vector<pii>
#define PI 													3.141592653
#define MLL 												map<ll,ll>
#define fbo 												find_by_order
#define ook 												order_of_key
#define printclock                  cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define debug1(a) 									cout<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) 								cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl
#define debug3(a,b,c)								cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl
#define debug4(a,b,c,d) 						cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl
mt19937 														rng(chrono::steady_clock::now().time_since_epoch().count());
void randomize(vr &in,ll x)					{f(0,in.size()-1)in[i]=rand()%x + 1;}
ll gcd(ll a, ll b)									{if(!b)return a;return gcd(b, a % b);}
ll lcm(ll a , ll b)									{return (a*b)/ gcd(a,b);}
ll modmul(ll a, ll b,ll mod)        { return ((a%mod) * (b%mod)) % mod;}
ll modadd(ll a , ll b,ll mod)       { return((a%mod)+(b%mod)+mod)%mod;}
ll modsub(ll a , ll b,ll mod)       {return((a%mod) - (b%mod) + mod)%mod;}
ll moduloMul(ll a,ll b,ll mod)			{ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;a = (2 * a) % mod;b >>= 1;}return res;}
ll power(ll x,ll y,ll p=LLONG_MAX)  {ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}ll XFEEA,YFEEA,GCDFEEA;
double power2(double x, ll y)       {double res = 1;while (y > 0){if (y & 1)res =(double) (res*x);y = y>>1;x =(double)(x*x);}return res;}
void extendedEuclidAlgo(ll a,ll b)  {if(b==0){XFEEA=1;YFEEA=0;GCDFEEA=a;return;}extendedEuclidAlgo(b,a%b);ll cx=YFEEA;ll cy=XFEEA-(a/b)*YFEEA;YFEEA=cy;XFEEA=cx;}
ll modInverse(ll n,ll m)            {extendedEuclidAlgo(n,m);return (XFEEA%m+m)%m;}
ll CmP(ll n, ll r, ll p=M1)         {if (r==0)return 1;ll fac[n+1];fac[0] = 1;for (ll i=1 ; i<=n; i++)fac[i] = fac[i-1]*i%p;return (fac[n]* modInverse(fac[r], p) % p *modInverse(fac[n-r], p) % p) % p;}
bool isSAFE(ll i,ll j,ll m,ll n)		{return (i>=1 && i<=m && j>=1 && j<=n);}
typedef                             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> orderedset;

/*find_by_order(ll k){returns the iterator to the kth smallest element,start from 0,O(logn)}
order_of_key(ll k){returns the number of elements in the set which are strictly less than our k,O(logn)}*/

//vector<vr> g,mat;
vector<vvr> dp;
//vr  ;
ll n,d;
ll go(ll index,ll Msum)
{
	Msum%=d;
	if(index==n)
	{
		if(Msum==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	ll ans=0;
	f(0,9)
	{
		if(dp[index][Msum][i]==-1)
		{
			dp[index][Msum][i]=go(index+1,Msum+i);
		}
		ans=modadd(ans,dp[index][Msum][i],M1);
	}
	return ans;
}
void solve(){}
void ask(){}

signed main()
{
	rohitaas_15();
	ll t=1;
	//cin>>t;
	ll cases=t;
	while(t--)
	{
		string k;
		cin>>k>>d;
		n=k.length();
		dp.resize(n+1,vvr(101,vr(10,-1)));
		go(0,0);
		ll sum=0;
		f(0,n-2)
		{
			f2(1,9)
			{
				sum=modadd(dp[i+1][0][j],sum,M1);
				//debug
			}
		}
		ll prev=0;
		//debug1(sum);
		f(0,n-1)
		{
			if(k[i]=='0' && i!=n-1)
			{
				con;
			}
			if(i==n-1)
			{
				ll start;
				(i==0)? start=1 : start=0;
				f2(start,k[i]-'0')
				{
						ll modulo=modadd(prev,j,d);
						if(modulo==0)
						{
							sum=modadd(sum,1ll,M1);
						}
				}
			}
			else
			{
				ll start;
				(i==0)? start=1 : start=0;
				f2(start,k[i]-'0' -1)
				{
					ll modulo=modadd(prev,j,d);
					f3(0,9)
					sum=modadd(sum,dp[i+1][modulo][kk],M1);
				}
			}
			prev=modadd(prev,k[i]-'0',d);
			//debug2(prev,sum);
		}
		co(sum);


	}
	//printclock;
}

	/*cout<<"Case #"<<cases-t<<": ";*/

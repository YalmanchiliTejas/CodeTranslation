#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename Arg1>
void pn(Arg1&& arg1)
{ cout<<arg1<<"\n";}
template <typename Arg1, typename... Args>
void pn(Arg1&& arg1, Args&&... args)
{ cout<<arg1<<"\n"; pn(args...); }

template <typename Arg1>
void ps(Arg1&& arg1)
{ cout<<arg1<<" ";}
template <typename Arg1, typename... Args>
void ps(Arg1&& arg1, Args&&... args)
{ cout<<arg1<<" "; ps(args...); }

template <typename Arg1>
void pvs(Arg1&& arg1, ll n)
{ for(ll i=0;i<n;i++)ps(arg1[i]); }
template <typename Arg1>
void pvn(Arg1&& arg1, ll n)
{ for(ll i=0;i<n;i++)pn(arg1[i]); }

template <typename Arg1>
void bug(Arg1&& arg1)
{ cout<<"->"<<arg1<<endl; }

ll lcm(ll a,ll b) 
{ return (a*b)/__gcd(a,b); }

ll mulmod(ll a,ll b,ll mod) 
{ ll res=0; a=a%mod; 
    while(b>0)
    { if(b%2==1) res=(res+a)%mod; 
      a=(a*2)%mod; b/=2; }
    return res % mod; } 

ll powmod(ll x,ll y,ll p) 
{ ll res=1; x=x%p;
    while(y>0) 
    { if (y&1) res=(res*x)%p; 
      y=y>>1; x=(x*x)%p; } 
    return res; } 

ll modInverse(ll n, ll p) 
{ return powmod(n, p-2, p); } 

ll log(ll n, ll b)
{ ll c=0;
	while(n>(b-1))
	{ c++; n/=b; } return c; }

ll fib(ll n) 
{ double phi=(1+sqrt(5))/2; 
  return round(pow(phi,n)/sqrt(5)); } 

vector<bool> prime;
void sieve(int n)
{ prime.resize(n,true);
	for(int p=2;p*p<=n;p++)
		if(prime[p])
			for(int i=p*p;i<=n;i+=p)
				prime[i]=false; }

void yes(){pn("Yes");}
void no(){pn("No");}
void bug(){cout<<"here"<<endl;}

#define MOD 1000000007 //10^9+7
#define pi 3.14159265358979323846
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define fn(i,s,d) for(i=s;i<d;i++)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define pl pair<ll,ll>
#define pd pair<double,double>
#define vl vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vpl vector<pl>
#define vpd vector<pd>
#define vs vector<string>
#define vvl vector<vl>
#define vvs vector<vs>
#define vvpl vector<vpl>
#define ff first
#define ss second
#define um unordered_map
#define dsort(v) sort(v); reverse(v);
#define maxpq(v) priority_queue<v>
#define minpq(v) priority_queue<v,vector<v>,greater<v>>

void solve()
{
	ll i,j;
	ll n;
	cin>>n;
	if(n>=30)
		yes();
	else
		no();
}

int main()
{
	#ifdef Deeksha
		// freopen("../Downloads/validation_input.txt", "r", stdin);
		freopen("../Downloads/_input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
	std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();/* 
	ll t;
	cin>>t;
	for(ll tt=1;tt<=t;tt++)
	{
		// cout<<"Case #"<<tt<<": ";
		solve();
	}
	//*/
}


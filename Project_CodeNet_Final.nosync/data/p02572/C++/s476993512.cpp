#include<bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#define pi 3.141592653589
#define MOD 1000000007
#define to() int t; cin>>t; while(t--)
#define pb push_back
#define in insert
#define mp make_pair
#define ff first
#define ss second
#define si(s) s.size()
#define fori(it,v) for(it=v.begin();it!=v.end(); it++) 
#define for1(low,high,k) for(int i=low;i<high;i+=k)
#define for11(low,high,k) for(int j=low;j<high;j+=k)
#define for2(low,high,k) for(int i=low;i<=high;i+=k)
#define rev(high,low,k)  for(int i=high;i>=low ;i-=k)
#define all(x) x.begin(), x.end()
#define fil(x,i) memset(x,i,sizeof(x));
#define setbits(x) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout) 
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

inline ll power(ll a, ll n, ll m)
{
if(n==0) return 1;
ll p=power(a,n/2,m);
p=(p*p)%m;
if(n%2) return (p*a)%m;
else return p;
}


int main()
{
	boost;
	int n; cin>>n;
	vector<ll>v(n);
	for1(0,n,1) cin>>v[i];
	vector<ll>pro(n);
	pro[n-1]=v[n-1]%MOD;
	for(int j=n-2;j>=0;j--){
		pro[j]=(pro[j+1]+v[j])%MOD;		
	}
	
	ll ans=0;
	for(int i=0;i<n-1;i++){
		ll val=v[i]%MOD;
		ans=(ans+( val*pro[i+1])%MOD)%MOD;
	}
	ans%=MOD;
	cout<<ans<<endl;
	
return 0;
}

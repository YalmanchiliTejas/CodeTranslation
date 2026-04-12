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

void i_o() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
}

int main()
{
	boost;
	i_o();
	ll n,x,m; cin>>n>>x>>m;
	vector<ll>v;
	unordered_map<ll,int>um;
	ll ans=0;
	while(n>0  && um.find(x)==um.end()){
		um[x]=v.size();
		v.pb(x); ans+=x;
	//	trace(x,v.size()-1);
		n--;
		x=(x*x)%m;
	}
	if(n>=1 && x>0){
		int len=v.size()-um[x];
		//trace(len);
		//trace(x,um[x]);
		ll r=n/(len*1LL);
		if(r>0){
			ll sum=0;
			for1(um[x],(int)v.size(),1) sum+=v[i];
			ans+=r*sum;
		}
		int d=n%len;
		for(int i=um[x];i<um[x]+d;i++) ans+=v[i];
	}

	cout<<ans<<endl;

	return 0;
}

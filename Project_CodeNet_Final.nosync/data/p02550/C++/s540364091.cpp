/*
	Nishant Singh
	nishant.ns19@gmail.com
*/
#include <bits/stdc++.h>
#include <functional> 
#include <iostream> 
// ******** Big Integer ********
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// #define ll1024  int1024_t
// ******** Big Integer ********
// ******** Using PBDS ********
// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ook order_of_key    //count of strictly smaller elements
// #define fbo find_by_order   //find element at an index 
// ******** Using PBDS ********
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define vll vector<ll>
#define vec vector
#define setcount(x) __builtin_popcountll(x)
#define f first
#define s second
#define mp make_pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define REV(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define in insert
#define init(x,a) memset(x,a,sizeof(x))
#define all(c) c.begin(),c.end()
#define pq priority_queue
#define ffl fflush(stdout)
#define mset multiset
#define out(x) cout<<#x<<" = "<<" "<<x<<"\n";
#define ub upper_bound
#define lb lower_bound 
#define ln "\n"
#define Y "YES"
#define N "NO"
ll mod;
ll const inf=2e18;
// ******** Using PBDS ********
// typedef tree<long long, null_type, less<long long>, rb_tree_tag, 
//              tree_order_statistics_node_update> 
//                 os; 
// ******** Using PBDS ********
inline ll add(ll a,ll b) 
{ 
	return (a%mod + b%mod + mod)%mod; 
}
inline ll mul(ll a,ll b) 
{ 
	return (a%mod * b%mod + mod)%mod; 
}
inline ll sub(ll a,ll b) 
{ 
	return (a%mod - b%mod + mod)%mod; 
}
ll gcd(ll a,ll b)
{
	if (b == 0) 
		return a; 
	return gcd(b, a % b);  
}
ll modexp(ll x, ll n){
	if(n==0){
		return 1;
	}
	else if(n&1){
		return (modexp((x*x)%mod, n/2)%mod * x%mod)%mod;
	}
	else{
		return (modexp((x*x)%mod, n/2)%mod);
	}
}
ll modinv(ll n)
{
	return modexp(n,mod-2);
}
// ******** GLOBAL VARIABLES ********
// ******** GLOBAL VARIABLES ********
void solve(){
	ll n,x,m;
	cin>>n>>x>>m;
	mod=m;
	ll temp[m+10];
	temp[0]=x;
	ll ans=x;
	map<ll,ll> done;
	ll st=-1,en=-1;
	ll cur=x;
	done[cur]=0;
	for(ll i=1;i<=m;i++){
		cur=mul(cur,cur);
		if(done.find(cur)!=done.end())
		{
				st=done[cur];
				en=i-1;
				break;
		}
		// cout<<cur<<" ";
		done[cur]=i;
		temp[i]=cur;
		ans+=temp[i];
		temp[i]+=temp[i-1];
		if(i==n-1)
		{
			cout<<ans;
			return;
		}
	}
	if(st==-1)
	{
		cout<<ans;
		return;
	}
	// cout<<ans<<endl;
	ll left=n-en-1;
	ll count=left/(en-st+1);
	ll rem=left%(en-st+1);
	// out(left);
	// out(count);
	// out(rem);
	// out(st);
	// out(en);
	// out(temp[st]);
	// out(temp[en]);
	if(st==0)
	{
		ans=ans+(count*temp[en]);
		if(rem>0)
			ans=ans+temp[rem-1];
	}
	else
	{
		ans=ans+(count*(temp[en]-temp[st-1]));
		if(rem>0)
			ans=ans+(temp[st+rem-1]-temp[st-1]);
	}
	cout<<ans<<endl;
}  
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T=1;
	// cin>>T; 	
	for(int t=1;t<=T;t++)
	{
		// cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}
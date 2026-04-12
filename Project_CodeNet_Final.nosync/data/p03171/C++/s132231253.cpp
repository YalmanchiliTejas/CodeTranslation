#include <bits/stdc++.h>
#include <functional>
#include<stdio.h>
using namespace std;
#define ll       	long long int
#define dd      	long double
#define pb          push_back
#define pf          push_front
#define pi         pair<ll,ll>
#define vi          vector<ll>
#define vpi        vector<pi>
#define mi          map<ll,ll>
#define vvi         vector<vector<ll>>
#define mpi         map<pi,ll>
#define pipi        pair<ll,pair<ll,ll> >
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define x         first
#define y         second
#define sz(x)       (ll)x.size()
#define g        	endl
#define PI          3.141592653589
#define bs(v,n)     binary_search(all((v)),(n))
#define lb(v,n)     lower_bound(all((v)),(n))
#define ub(v,n)     upper_bound(all((v)),(n))
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define rf(s)       for(auto &c : s)
#define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++) //use Iterator
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define M           1000000007
#define ef          else if
#define yes       cout<<"YES"<<endl;
#define no        cout<<"NO"<<endl;
#define C         continue;
#define wa(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#define debug(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
#define debugp(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i.x<<","<<i.y<<" | "; cout<<endl
const ll N = 1e5+5;
#include <ext/pb_ds/tree_policy.hpp>      // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>     //common file
using namespace __gnu_pbds;
typedef tree<pipi,null_type,less<pipi>,rb_tree_tag,tree_order_statistics_node_update> pbds;
#define fbo find_by_order
#define ook order_of_key

//const ll inf=1e17+7;
/*
template<class T>
T big(T a, T b) { return a>b ? a : b; }*/
ll gcd(ll a, ll b) {  if (a == 0)  return b; return gcd(b % a, a); } 
/*
ll lcm(ll a, ll b) { return (a*b)/gcd(a,b); } 
bool M(double a,double b) {return a/b - floor(a/b);}
ll occurs(vi v,ll n)  {  auto it=lb(v,n);auto it1=ub(v,n);ll x=it1-it;return x;}
ll logb(ll base, ll x) {return (log(x) / log(base));}*/
ll power(ll x, ll y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}/*
ll factors(ll ans){
    ll count=0;
    for (ll i=1; i<=sqrt(ans); i++) { 
        if (ans%i == 0) 
        {if (ans/i == i) count++;
            else count+=2;} 
    }
    return count;     
}
bool isSubSequence(string str1, string str2, ll m, ll n)  // str1<str2
{ 
  
    if (m == 0) return true; 
    if (n == 0) return false; 
  
  	if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    return isSubSequence(str1, str2, m, n-1); 
} 
bool search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}
*/
ll t1[3001][3001][2];
ll n1;
vi a(3001);
ll solve(ll n,ll m,ll flag)
{
	if(n<0 || m<0 || n>=n1 || m>=n1 || n>m)
	return 0;
	if(t1[n][m][flag]!=-1)
	return t1[n][m][flag];
	if(flag==0)
	return t1[n][m][flag]=max(a[n]+solve(n+1,m,1-flag),a[m]+solve(n,m-1,1-flag));
	else
	return t1[n][m][flag]=min(-a[n]+solve(n+1,m,1-flag),-a[m]+solve(n,m-1,1-flag));
}
signed main()
{
	tezz
	ll t=1;
	//cin>>t;
	while(t--)
	{
		ll i;
		cin>>n1;
		a.resize(n1);
		fo(i,0,n1)
		{
			cin>>a[i];
		}
		memset(t1,-1,sizeof(t1));
		ll ans=solve(0,n1-1,0);
		cout<<ans<<g;
	}
	return 0;
}
/*||>>>> Praveen Ojha <<<<>>>> 29 August 2019 <<<<>>>> 18:19:00 <<<<||*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define mod 1000000007
#define inf (int)1e18+5
#define sz(x) (int)x.size()
#define PI 3.141592653589793238510
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define __ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vpii vector<pair<int,int> > 
#define vvi vector<vector<int> >
#define PRINT_TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." <<endl;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename   enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
typedef long double ld;
typedef pair<int,int> pii;
//Read Problems Carefully & Check for corner cases N=0,1 ?
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
string s;
int d,n,dp[10001][101][2];
void add(int &a,int b){
	a+=b;
	if(a>=mod)
		a-=mod;
}
int solve(int ind,int sumi,int lim){
	if(ind==n){
		if(sumi%d==0)
			return 1;
		else
			return 0;
	}
	int &ans=dp[ind][sumi][lim];
	if(ans!=-1)
		return ans;
	ans=0;
	if(lim){
		int lst=s[ind]-'0';
		for(int i=0;i<=lst;i++){
			add(ans,solve(ind+1,(sumi+i)%d,i==lst));
		}
	}
	else{
		for(int i=0;i<=9;i++){
			add(ans,solve(ind+1,(sumi+i)%d,lim));
		}
	}
	return ans;
}
int32_t main(){__
	cin>>s>>d;
	n=sz(s);
	memset(dp,-1,sizeof dp);
	int ans=solve(0,0,1)-1;
	if(ans<0)
		ans+=mod;
	cout<<ans<<"\n";
return 0;
}
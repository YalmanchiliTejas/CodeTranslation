#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define mk make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define sz(v) (v).size()
#define inf 1e18
#define md 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tihs if(fopen("inp.txt","r"))freopen("inp.txt", "r", stdin),freopen("out.txt", "w", stdout);
using namespace std;
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 

#define M 110
#define N 3010
ll n,k,a[N],dp[N][N][2];
ll f(ll left,ll right,ll cond){
	if(left>right) return 0;
	if(dp[left][right][cond]!=-1) return dp[left][right][cond];
	ll ans;
	if(cond)
		ans=max(f(left+1,right,!cond)+a[left],f(left,right-1,!cond)+a[right]);
	else 
		ans=min(f(left+1,right,!cond)-a[left],f(left,right-1,!cond)-a[right]);
	return dp[left][right][cond]=ans;
}
int main(){
	IOS;
	tihs;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	rep(i,0,n)cin>>a[i];
	cout<<f(0,n-1,1);
	return 0;
}
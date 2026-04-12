#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
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
#define md 998244353
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using o_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define M 4010

ll n,s;
ll a[M];
ll dp[M][M];
ll f(ll pos, ll sum){
	if(sum > s) return 0;
	if(pos == n + 1){
		return sum == s;
	} 
	if(sum == s){
		return n + 2 - pos;
	}
	if(dp[pos][sum] != -1) return dp[pos][sum];
	ll ans = f(pos + 1, sum + a[pos]);
	if(!sum) (ans *= pos) %= md;
	(ans += f(pos + 1, sum)) %= md;
	return dp[pos][sum] = ans;
}
int main(){
	IOS;
	memset(dp,-1,sizeof(dp));
	cin>>n>>s;
	rep(i,1,n+1)cin>>a[i];
	
	cout<<f(1,0);
	
	
	
	return 0;
}


// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define ll long long int
#define ld double
#define pi pair<ll,ll>
#define pb push_back
#define pf push_front
#define pu push
#define po pop
#define fi first
#define se second
#define mk make_pair
#define ve vector
#define lr(n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define be begin
#define sz(a) (ll)a.size()
#define INF 1e18
 
typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
 
ll mod=1e9+7;
// ll gcd(ll a, ll b){
//     if(a<b) swap(a,b);
//     if(b==0) return a;
//     return gcd(b,a%b);
// }
 
// ll fun(ll x, ll y){
//     ll rem=1;
//     while(y!=0){
//         if(y%2==1){
//             rem=(rem*x)%mod;
//         }
//         x=(x*x)%mod;
//         y/=2;
//     }
//     return rem;
// }

ll n;
ll ar[3001]={0};
ll dp[3001][3001];
void fun(ll i,ll j){
	if(dp[i][j]!=-1) return;
	if(i==j){
		dp[i][j]=ar[j]-ar[i-1];
		return;
	}
	fun(i,j-1);
	fun(i+1,j);
	dp[i][j]=max(-ar[i-1]+ar[j]-dp[i+1][j], ar[j]-ar[i-1]-dp[i][j-1]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	lr(n){
		ll x;
		cin>>x;
		ar[i+1]=ar[i]+x;
	}
	for(ll i=0;i<=n;i++) for(ll j=0;j<=n;j++) dp[i][j]=-1;
	fun(1,n);
	cout << 2*dp[1][n]-ar[n]+ar[0] << "\n";
	return 0;
}
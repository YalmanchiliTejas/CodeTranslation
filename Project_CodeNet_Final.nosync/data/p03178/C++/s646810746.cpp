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

ll dp[10010][110];
char s[10010];
ll d,n;
ll ans=0;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>&s[1];
	cin>>d;
	n=strlen(&s[1]);
	for(ll i=0;i<=n;i++) for(ll j=0;j<d;j++) dp[i][j]=0;
	dp[0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll k=0;k<d;k++){
			for(ll j=0;j<10;j++){
				dp[i][(k+j)%d]=(dp[i][(k+j)%d]+dp[i-1][k])%mod;
			}
		}
	}
	ll x=0;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<(s[i]-'0');j++){
			ans=(ans+dp[n-i][(d-(x+j)%d)%d])%mod;
		}
		x=(x+s[i]-'0')%d;
	}
	if(x==0) ans++;
	cout << (ans-1+mod)%mod << "\n";
	return 0;
}
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
typedef long long int ll;
const ll N = 2e5+9;
const ll p = 31;
// const ll m = 1e9 + 7;
const ll inf= 1e5;
const ll mod =1e9+7	;
#define x first
#define y second
#define pb push_back
#define mp make_pair
using pii = pair<int, int>;
ll powm(ll a, ll b) { a = a%mod;ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
string k;ll d;
std::vector<std::vector<ll>> dp;


int main(){   
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);                      
    ll T= 1;
    // cin >> T;
   
    while(T--){
    	cin>>k;cin>>d;
    	ll n = k.size();
    	// cout<<n<<'\n';
    	dp.resize(d,vector<ll>(2));
    	dp[0][0] = 1;
    	for(int i = 0;i<n;i++){
    		std::vector<std::vector<ll>> ndp(d,vector<ll>(2));
    		for(int j = 0;j<10;j++){
    			for(int l = 0;l<d;l++){
    				ndp[(l+j)%d][1] += dp[l][1];
    				ndp[(l+j)%d][1]%=mod;
    			}
    		}
    		for(int j = 0;j<(k[i]-'0');j++){
    			for(int l = 0;l<d;l++){
    				ndp[(l+j)%d][1] += dp[l][0];
    				ndp[(l+j)%d][1]%=mod;
    			}
    		}
    		for(int l = 0;l<d;l++){
				ndp[(l+(k[i]-'0'))%d][0] += dp[l][0];
				ndp[(l+(k[i]-'0'))%d][0]%=mod;
			}
			// for(int j = 0;j<d;j++){
			// 	cout<<ndp[j][1]<<" ";
			// }
			// cout<<'\n';

			// for(int j = 0;j<d;j++){
			// 	cout<<ndp[j][0]<<" ";
			// }
			// cout<<"\n\n";
			dp=ndp;

    	}
    	ll ans = dp[0][0]+dp[0][1]-1 +mod;
    	ans%=mod;
    	cout<<ans<<'\n';
    }
}
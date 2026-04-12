/*input
98765432109876543210
58

1000000009
1

30
4
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define sz(x) (int)(x).size()
#define pb push_back

typedef long long int ll;
typedef vector<int> vi;

const ll inf = 1e9;
const ll mod=1000000007;

ll powmod(ll a,ll b,ll mo=mod){ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}

inline ll inv_(ll a) {return powmod(a, mod-2, mod);}
inline ll add(ll a, ll b){a%=mod; b%=mod; a+=b;if(a>=mod)a-=mod;return a;}
inline ll mul(ll a, ll b){a%=mod; b%=mod; return a*1ll*b%mod;}
inline ll sub(ll a, ll b){a%=mod; b%=mod; a-=b;if(a<0)a+=mod;return a;}


const int MAXN = 100005;
int d;
string k;

ll dp[10005][105][2];

ll solve(int idx, int sum, bool flag){
	// cout << idx << " " << k[idx] << " -- " << sum << " " << flag << endl;
	if(idx >= sz(k))return (sum % d == 0);
	if(dp[idx][sum][flag] != -1)return dp[idx][sum][flag];
	ll ans = 0;
	if(!flag){
		for(int i = 0; i <= 9; ++i){
			ans = ans + solve(idx + 1, (sum + i) % d, false) % mod;
		}
	}
	else{
		for(int i = 0; i < (k[idx] - '0'); ++i){
			ans = ans + solve(idx + 1, (sum + i) % d, false) % mod;
		}	
		ans = ans + solve(idx + 1, (sum + (k[idx] - '0')) % d, true) % mod;
	}
	ans = ans % mod;
	return dp[idx][sum][flag] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	
	memset(dp, -1, sizeof(dp));

	cin >> k >> d;
	
	ll ans = solve(0, 0, true);
	
	cout << (ans + mod - 1) % mod << endl;
	
    return 0;
}



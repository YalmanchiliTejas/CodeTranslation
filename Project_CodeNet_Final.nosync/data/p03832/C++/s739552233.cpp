#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1e9 + 7;
const int Maxn = 1e3 + 10;
const ll Inf = 1e16;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll pw = b, j = 1; j <= p; j += j, pw = mul(pw, pw)) if(p & j) res = mul(res, pw);
	return res;
}
ll f[Maxn], iv[Maxn];

ll nCr(ll n, ll r){
	if( (r < 0) || (n < r) || (n < 0)) return 0;
	return mul(f[n], mul(iv[r], iv[n - r]));
}

ll dp[Maxn][Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i < Maxn; i++) f[i] = mul(f[i - 1], i);	
	for(int i = 0; i < Maxn; i++) iv[i] = bin_pow(f[i], Mod - 2);
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	dp[0][0] = 1;
	ll wy, wy2;
	for(int i = 1; i <= b; i++){
		for(int j = 0; j <= n; j++){
			wy = 1;
			for(int Fi = 0; j + Fi * i <= n; Fi ++){
				if((Fi == 0) || ((c <= Fi) && (Fi <= d) && (a <= i) && (i <= b)) ){
					wy2 = mul(wy, iv[Fi]);
					dp[i][j + Fi * i] += mul(dp[i - 1][j], wy2);
					dp[i][j + Fi * i] %= Mod;
				}
				
				wy *= nCr(n - j - (Fi * i), i);
				wy %= Mod;
			}
		}
	}
	cout << dp[b][n];
	return 0;
}


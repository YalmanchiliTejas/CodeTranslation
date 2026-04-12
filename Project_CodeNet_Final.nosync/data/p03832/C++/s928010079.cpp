#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

const long long MAX = 2e5+100;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll dp[1010][1010];

ll powmod(ll a, ll x){
	if(x == 0){return 1;}
	
	ll r = powmod(a, x/2);
	if(x%2){
		return ((r*r)%MOD)*a%MOD;
	}
	else{
		return r*r%MOD;
	}
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	COMinit();
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	
	//print(powmod(4, 1))
	memset(dp, 0, sizeof(dp));
	dp[a-1][0] = 1;
	rep(i, a, b){
		rep(k, 0, n){
			dp[i][k] += dp[i-1][k];
			dp[i][k] %=MOD;
		}
		
		for(ll j = c; j <= d && i*j <= n; j++){
			rep(k, 0, n){
				if(k+i*j <= n){
					ll tmp = COM(n-k, i*j)*fac[i*j]%MOD;
					tmp *= finv[j];
					tmp %= MOD;
					tmp *= powmod(finv[i], j);
					tmp %= MOD;
					//if(i == 2 && j == 2 && k == 0){print(tmp)}
					
					dp[i][k+i*j] += tmp*dp[i-1][k];
					dp[i][k+i*j] %= MOD;
				}
			}
			//print(tmp)
		}
	}
	//rep(i, a-1, b){rep(j, 0, n){cout << dp[i][j] << " ";}cout << endl;}
	
	print(dp[b][n])
	return 0;
}
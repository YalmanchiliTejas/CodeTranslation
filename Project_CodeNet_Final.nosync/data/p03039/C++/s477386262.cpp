#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, m, k;

ll po(ll a, ll b, ll c, ll d){
	ll ans = 0;
	ans += a*(1+a+b)*(b+1)/2;
	ans += b*(1+b+c)*(c+1)/2;
	ans += c*(1+c+d)*(d+1)/2;
	ans += d*(1+d+a)*(a+1)/2;
	//print(ans)
	return ans%MOD;
}

const int MAX = 510000;

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

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	ll ans = 0;
	rep(i, 1, n){
		rep(j, 1, m){
			ans += po(i-1, j-1, n-i, m-j);
		}
	}
	ans /= 2;
	ans %= MOD;
	//print(ans)
	COMinit();
	ans *= COM(n*m-2, k-2);
	ans %= MOD;
	print(ans)
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ers erase
#define ins insert
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) cout << #x << "= " << x << '\n';
#define kill(x) return cout << x, 0;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1000 * 1000 * 1000 + 7;
const ll N = 1e3 + 10;
const ll INF = 1e18;
const ll LOG = 25;

ll fac[N], im[N], dp[N][N], n, A, B, C, D;

ll POW(ll x, ll t){
	if (t == 0) return 1;
	if (t % 2 == 0) return POW(x * x % MOD, t / 2);
	return x * POW(x, t - 1) % MOD;
}

ll choose(ll x, ll y){
	if (y > x || x < 0 || y < 0) return 0;
	ll res = fac[x];
	res *= im[y];
	res %= MOD;
	res *= im[x - y];
	res %= MOD;
	return res;;
}


int main(){
	fac[0] = 1, im[0] = 1;
	for (int i = 1; i < N; i++){
		fac[i] = fac[i - 1] * i % MOD;
		im[i] = POW(fac[i], MOD - 2);
	}
	cin >> n >> A >> B >> C >> D;
	dp[0][0] = 1;
	//cout << choose(5, 3);
	for (int i = 1; i <= B; i++){
		for (int j = 0; j <= n; j++){
			ll cnt = 1;
			for (int ted = 0; j + ted * i <= n; ted ++){
				if (ted != 0){
						cnt *= choose(n - j - (i * (ted - 1)), i);
						cnt %= MOD;
				}
					
				if ((ted == 0) || ((ted >= C && ted <= D) && (i >= A && i <= B))){
					ll ted2 = cnt * im[ted] % MOD;
					dp[i][ted * i + j] += dp[i - 1][j] * ted2 % MOD;
					dp[i][ted * i + j] %= MOD; 
				}
			}
			
		}
	}
	cout << dp[B][n];

	
	return 0;

}

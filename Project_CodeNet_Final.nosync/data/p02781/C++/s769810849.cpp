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

const ll MAX = 1000;
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
	
	string s;
	ll k;
	cin >> s >> k;
	
	ll d = s.size();

	ll a[d];
	zep(i, 0, d){
		a[i] = s[i]-'0';
	}
	//printa(a, 0, 1)
	COMinit();
	ll ans = 0;
	zep(i, 0, d){
		//print(ans);
		if(i == 0){
			if(d-1 >= k-1){
				ans += (a[i]-1)*COM(d-1, k-1)*pow(9, k-1);
			}
			if(d-1 >= k){
				ans += COM(d-1, k)*pow(9, k);
			}
			k--;
		}
		else{
			if(a[i] > 0){
				if(d-1-i >= k-1){
					ans += (a[i]-1)*COM(d-1-i, k-1)*pow(9, k-1);
				}
				if(d-1-i >= k){
					ans += COM(d-1-i, k)*pow(9, k);
				}
				k--;
			}
		}
		
		if(k < 0){
			break;
		}
	
		if(k == 0 && i == d-1){
			ans++;
		}
	}
	print(ans)
	return 0;
}
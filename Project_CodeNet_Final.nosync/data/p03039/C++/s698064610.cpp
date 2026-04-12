#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;

/*** MOD CALCULATION ***/

const int MOD = 1e9+7;
const int MAX = 1'000'005;

ll addM(ll a, ll b){
	return ((a % MOD) + (b % MOD)) % MOD;
}

ll mulM(ll a, ll b){
	return ((a % MOD) * (b % MOD)) % MOD;
}

ll powM(ll a, ll b){
	if(b == 0) return 1;
  	else if(b == 1) return a % MOD;
  	else if(b%2==0) return mulM(powM(a, b/2), powM(a, b/2));
  	else return mulM(a, mulM(powM(a, (b-1)/2), powM(a, (b-1)/2)));
}

// b^{-1} = b^{p-2} (mod p)
// a/b = a*b^{p-2} (mod p)
ll divM(ll a, ll b){ 
  	return mulM(a, powM(b, MOD-2));
}

// n!, (n!)^{-1} のテーブル作成
ll fac[MAX], finv[MAX], inv[MAX];
void COMBinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    rep3(i,2,MAX-1){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COMB(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

/*** MOD CALCULATION ここまで ***/

void Main(){
    int n, m, k; cin >> n >> m >> k;
    COMBinit();
    
    ll t1 = mulM(m, m);
    ll t2 = mulM(mulM(n-1, n), n+1);
    ll tmp1 = divM(mulM(t1, t2), 6);

    t1 = mulM(n, n);
    t2 = mulM(mulM(m-1, m), m+1);
    ll tmp2 = divM(mulM(t1, t2), 6);
    
    // cout << tmp1 << " " << tmp2 << endl;
    // cout << COMB(n*m-2, k-2) << endl;
    ll ans = mulM(addM(tmp1, tmp2), COMB(n*m-2, k-2));
    cout << ans << endl;
    return;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
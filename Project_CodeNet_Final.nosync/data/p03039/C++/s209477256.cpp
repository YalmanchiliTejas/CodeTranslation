#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

const ll MOD = 1e9+7;
const int MAX = 200050;
long long fac[MAX], finv[MAX], inv[MAX];
 
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

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll n, m, k;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	COMinit();
	cin >> n >> m >> k;
	ll ret = 0;
	rep(d,1,n) {
		ll loc = (n-d) * COM(n*m-2,k-2) % MOD;
		loc = loc * d % MOD;
		loc = loc * m * m % MOD;
		ret = (ret + loc) % MOD;
	}
	rep(d,1,m) {
		ll loc = (m-d) * COM(n*m-2,k-2) % MOD;
		loc = loc * d % MOD;
		loc = loc * n * n % MOD;
		ret = (ret + loc) % MOD;
	}
	cout << ret << '\n';
	return 0;
}

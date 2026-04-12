#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e3 + 5;

ll bin_pow(ll a, ll st){
	ll ans = 1ll;
	for(; st; st /= 2ll){
		if (st & 1){
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return ans;
}

ll get_inv(ll a){
	return bin_pow(a, MOD - 2);
}

ll c[MAXN][MAXN];
ll dp[MAXN];
ll inv[MAXN];
ll f[MAXN];
ll f_inv[MAXN];

void solve(){
	int n, A, B, C, D;
	scanf("%d%d%d%d%d", &n, &A, &B, &C, &D);
	f[0] = f_inv[0] = 1ll;
	REPN(i, 1, n){
		inv[i] = get_inv(i);
		f[i] = (f[i - 1] * i) % MOD;
		f_inv[i] = (f_inv[i - 1] * inv[i]) % MOD;
	}
	REPN(i, 0, n){
		c[i][0] = 1;
		REPN(j, 1, i){
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}

	dp[0] = 1;
	REPN(k, A, B){
		for(int i = n - 1; i >= 0; i--){
			ll cnt = (f[(C - 1) * k] * f_inv[C - 1]) % MOD;
			cnt = (cnt * get_inv(bin_pow(f[k], C - 1))) % MOD;
			REPN(j, C, D){
				int ind = i + k * j;
				if (ind > n){
					break;
				}
				cnt = (cnt * c[k * j][k]) % MOD;
				cnt = (cnt * inv[j]) % MOD;
				
				ll tmp = (c[ind][i] * dp[i]) % MOD;
				tmp = (tmp * cnt) % MOD;
				dp[ind] = (dp[ind] + tmp) % MOD;
			}
		}
	}
	
	printf("%lld\n", dp[n]);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}

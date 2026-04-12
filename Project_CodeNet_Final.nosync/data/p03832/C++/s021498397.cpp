#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pd(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%.12f",n)
#define psp printf(" ")
#define endc printf("\n")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e3 + 6;
const ll md = 1e9 + 7;

ll C[maxn][maxn];
ll dp[maxn][maxn];
ll f[maxn][maxn];
ll fact[maxn];

ll inv(ll x) {
	ll ex = md-2; ll ans = 1;
	while (ex > 0) {
		if (ex & 1 == 1) ans = (ans * x)%md;
		x = (x*x)%md; ex >>= 1;
	}
	return ans;
}

int main() {
	int n,a,b,c,d; sd(n); sd(a); sd(b); sd(c); sd(d);
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			if (j > i) { C[i][j] = 0; continue; }
			if (j == 0) { C[i][j] = 1; continue; }
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%md;
		}
		dp[a-1][i] = 0;
	}
	fact[0] = 1;
	for (int s = 1; s <= n; s++) {
		fact[s] = (fact[s-1] * s)%md;
		int curi = 0; f[s][0] = 1;
		for (int g = 1; g*s <= n; g++) {
			f[s][g] = f[s][g-1];
			for (int k = 1; k <= s; k++) {
				curi++;
				f[s][g] = (f[s][g]*curi)%md;
				f[s][g] = (f[s][g]*inv(k))%md;
			}
		}
	}
	dp[a-1][0] = 1;
	for (int s = a; s <= b; s++) {
		dp[s][0] = 1;
		for (int g = 1; g * s <= n; g++) {
			f[s][g] = (f[s][g] * inv(fact[g]))%md;
		}
		for (int m = 1; m <= n; m++) {
			dp[s][m] = 0;
			for (int g = c; g <= d; g++) {
				int y = g*s;
				if (y > m) break;
				ll cur = (C[m][y] * f[s][g])%md;
				dp[s][m] = (dp[s][m] + cur*dp[s-1][m - y])%md;
			}
			dp[s][m] = (dp[s][m] + dp[s-1][m])%md;
		}
	}
	
	pl(dp[b][n]); endc;	
}

#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e3 + 7, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return ll(a) * b % MOD; }
int qpow(int a, int b) { int r=1; for (;b;b>>=1) {if (b&1)r=mul(r,a);a=mul(a,a); } return r; }
int inv(int d) { return qpow(d, MOD - 2); }
int dp[N][N], C[N][N], n, a, b, c, d, g[N][N], ig[N][N], ii[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  rep(i, 0, N) C[i][0] = 1;
  rep(i, 1, N) rep(j, 1, i + 1) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
  rep(i, 0, N) {
  	g[i][0] = 1;
  	g[i][1] = i ? mul(g[i - 1][1], i) : 1;
  	rep(j, 2, N) g[i][j] = mul(g[i][j - 1], g[i][1]);
  	rep(j, 0, N) ig[i][j] = qpow(g[i][j], MOD - 2);
	}
	rep(i, 0, N) ii[i] = qpow(g[i][1], MOD - 2);
//rep(i, 0, 10) rep(j, 0, i + 1) cout << C[i][j] << " \n"[j == i];
	cin >> n >> a >> b >> c >> d;
	dp[a - 1][0] = 1;
	rep(i, a, b + 1) { 
		rep(j, 0, n + 1) {
			int &dij = dp[i][j];
			dij = dp[i - 1][j];
			rep(k, c, d + 1) {
				if (j - k * i < 0) break;
				dij = add(dij, mul(dp[i - 1][j - k * i], mul(C[j][k * i], mul(g[k * i][1], mul(ig[i][k], ii[k])))));
			}
		}
	}
	cout << dp[b][n];
	return 0;
}
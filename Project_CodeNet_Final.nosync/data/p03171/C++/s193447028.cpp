#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#define endl "\n"
#define fi first
#define se second
#define db double
#define gcd __gcd
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & (-x))
#define PII  pair<int, int> 
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, a, b) for(__typeof(b) i = a; i <= (b); i++)
#define Rep(i, a, b) for(__typeof(a) i = a; i >= (b); i--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
template<class T> inline T qmin(T a, T b) { return a < b ? a : b; }
template<class T> inline T qmax(T a, T b) { return a > b ? a : b; }
typedef long long ll;
typedef unsigned long long ull;
const db eps = 1e-9;
const db PI = acos(-1);
const int inf = 0x3f3f3f3f;
const int mod = (int)1e9 + 7;
const int maxn = (int)3e3 + 5;//remember to modify it, No RE or MLE
const ll INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;

ll qpow(ll x, ll y) { ll ret = 1; for( ; y; y >>= 1, x = (x * x) % mod) if(y & 1) ret = (ret * x) % mod; return ret; }

inline int read(){
	char ch = getchar();
	int x = 0, f = 1;
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

ll dp[maxn][maxn], sum[maxn];
int a[maxn];
int n;

ll dfs(int l, int r){
	if(dp[l][r] != INF) return dp[l][r];
	ll S = sum[r] - sum[l-1];
	dp[l][r] = max(S - dfs(l + 1, r), S - dfs(l, r - 1));
	return dp[l][r];
}

int main()
{
	n = read();
	rep(i, 1, n) a[i] = read(), sum[i] = sum[i-1] + a[i];
	memset(dp, 0x3f, sizeof dp);
	rep(i, 1, n) dp[i][i] = a[i];
	dfs(1, n);
	printf("%lld\n", dp[1][n] - (sum[n] - dp[1][n]));
	return 0;
}
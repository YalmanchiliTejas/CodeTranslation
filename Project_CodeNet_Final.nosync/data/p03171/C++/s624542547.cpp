#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define f first
#define s second
const int INF = 0x3f3f3f3f, MAXN = 3005;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
int N, ar[MAXN];
ll dp[MAXN][MAXN][2];
bool done[MAXN][MAXN][2];
ll f (int l, int r, int p){ //1 = maximize, 0 = minimize
	if (done[l][r][p]) return dp[l][r][p];
	done[l][r][p] = 1;
	if (l==r) return dp[l][r][p] = p?ar[l]:-ar[l];
	if (p) return dp[l][r][p] = max (f(l+1, r, 0)+ar[l], f(l, r-1, 0)+ar[r]);
	else return dp[l][r][p] = min (f(l+1, r, 1)-ar[l], f(l, r-1, 1)-ar[r]);
}
int main(){
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%d", &N);
	for (int i = 1; i<=N; i++) scanf("%d", &ar[i]);
	printf("%lld\n", f(1, N, 1));
}	
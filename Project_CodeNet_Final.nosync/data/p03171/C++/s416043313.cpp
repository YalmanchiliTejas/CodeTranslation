#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
using mat = vector<vector<ll>>;

inline void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[5001][5002];

ll a[3002];
ll dp[3002][3002];
ll n;

ll rec(int i, int j, bool isT){
	if(dp[i][j] != INF)return dp[i][j];
	ll &tmp = dp[i][j];
	if(i == j)return dp[i][j] = (isT ? a[i] : -a[i]);
	if(isT)tmp = max(rec(i + 1, j, false) + a[i], rec(i, j - 1, false) + a[j]);
	else   tmp = min(rec(i + 1, j, true) - a[i], rec(i, j - 1, true) - a[j]);
	return tmp;
}

signed main(){
	IOS();
	cin >> n;
	Fill(dp, INF);
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	ll ans = rec(1, n, true);
	cout << ans << endl;
	
}
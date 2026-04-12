#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
#include<iomanip>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const ll INF = 1000000007;
ll dp[3001][3001];
int flag[3001][3001];
vector<ll>a(3001);

ll f(int l,int  r) {
	if (flag[l][r])return dp[l][r];
	flag[l][r] = 1;
	if (l == r)return dp[l][r] = a[l];
	return dp[l][r] = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
}
int main() {
	int n;
	cin >> n;
	rep(i, n)cin >> a[i];
	ll ans = (f(0, n - 1));
	cout << ans;
	return 0;
}
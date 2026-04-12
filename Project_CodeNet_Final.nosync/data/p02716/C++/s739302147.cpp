#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[200005];
llint dp[200005][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j < 3; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = 0;
	
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < 3; j++){
			if(i+2 <= n+1) chmax(dp[i+2][j], dp[i][j] + a[i+1]);
			if(j+1 < 3) chmax(dp[i+1][j+1], dp[i][j]);
		}
	}
	cout << dp[n+1][n%2+1] << endl;
	
	return 0;
}
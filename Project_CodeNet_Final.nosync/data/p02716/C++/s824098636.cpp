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
llint dp[200005][3][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 2; k++){
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 2; k++){
				if(k == 0) chmax(dp[i+1][j][1], dp[i][j][k] + a[i+1]);
				
				llint nj = j;
				if(k == 0) nj++;
				if(nj < 3) chmax(dp[i+1][nj][0], dp[i][j][k]);
			}
		}
	}
	
	llint ans;
	if(n % 2) ans = max(dp[n][1][0], dp[n][2][1]);
	else ans = max(dp[n][0][0], dp[n][1][1]);
	
	cout << ans << endl;
	
	return 0;
}
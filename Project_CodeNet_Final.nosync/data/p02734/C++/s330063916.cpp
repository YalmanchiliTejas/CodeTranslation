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
#define llint long long
#define inf 1e18
#define mod 998244353
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint n, s;
llint a[3005];
llint dp[3005][3005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	dp[0][0] = 1;
	llint ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= s; j++){
			(dp[i+1][j] += dp[i][j]) %= mod;
			if(j+a[i+1] <= s){
				llint add = dp[i][j];
				if(j == 0) add *= (i+1), add %= mod;
				(dp[i+1][j+a[i+1]] += add) %= mod;
				if(j+a[i+1] == s) ans += add * (n-i) % mod, ans %= mod;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
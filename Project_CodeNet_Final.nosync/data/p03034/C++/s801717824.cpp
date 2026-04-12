#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps DBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, s[100010];
map<P, int> dp;
signed main() {
	cin >> n;
	rep(i, n)cin >> s[i];
	rep(i, n) {//2i+1回でゴール
		REP(j, n - 1) {//a-b=j
			if (n - 1 <= i * j + j)break;
			if ((n - 1 - i * j) % j == 0 && (n - 1 - i * j) / j * 2 <= 2 * i)continue;
			//2i回目の後いるのはi*j番
			if (i)dp[make_pair(i, j)] = dp[make_pair(i - 1, j)] + s[n - 1 - i * j] + s[i * j];
			else dp[make_pair(i, j)] = s[n - 1 - i * j] + s[i * j];
		}
	}
	int ans = 0;
	for (pair<P, int> p : dp) {
		ans = max(ans, p.second);
	}
	cout << ans << endl;
}
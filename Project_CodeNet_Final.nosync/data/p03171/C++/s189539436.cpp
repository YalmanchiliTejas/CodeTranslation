#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#include <functional>

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define MOD 1000000007LL
#define rep(i,a,n) for (int i=a ; i<n ; i++)
#define per(i,a,n) for (int i=n-1 ; i>=a ; i--)
#define LLINF (llong)1e18+5
#define INF 1e9+1
#define endl '\n'

using namespace std;
using llong = long long;
using VI = vector<int>;
using VLL = vector<long long>;
using PII = pair<int, int>;

//struct cmp {
//	bool operator() (pair<PII, int> a, pair<PII, int> b)
//	{
//		return a.ss > b.ss;
//	}
//};

int n;
VLL a;
vector<vector<llong>> dp;

llong dfs(int ll, int rr) {
	llong& ret = dp[ll][rr];
	if (ret != LLINF) return ret;
	if (ll == rr) return ret = a[ll];
	llong dfs1 = -dfs(ll + 1, rr) + a[ll];
	llong dfs2 = -dfs(ll, rr - 1) + a[rr];
	return ret = max(dfs1, dfs2);
}

int main()
{
	cin >> n;
	a = VLL(n);
	dp = vector<vector<llong>>(n, vector<llong> (n, LLINF));
	rep(i, 0, n) cin >> a[i];
	cout << dfs(0, n - 1);
}
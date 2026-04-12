#include <iostream>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <list>
#include <stack>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#define m7 1000000007
#define m9 1000000009
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second

using namespace std;


const pair<ll, ll> mp = make_pair(-1, -1);
pair<ll,ll> dp[3000][3000];

pair<ll,ll> solve(vector<int>& V, int beg, int end) {
	if (beg == end) {
		dp[beg][end].first = V[beg];
		dp[beg][end].second = 0;
		return make_pair(V[beg], 0);
	}
	if (dp[beg][end] != mp) {
		return dp[beg][end];
	}
	pair<ll, ll> x = solve(V, beg + 1, end);
	pair<ll, ll> y = solve(V, beg, end - 1);
	if (x.second + V[beg] > y.second + V[end]) {
		dp[beg][end].first = x.second + V[beg];
		dp[beg][end].second = x.first;
	}
	else {
		dp[beg][end].first = y.second + V[end];
		dp[beg][end].second = y.first;
	}
	return dp[beg][end];
}
int main()
{
	int n;
	cin >> n;
	vector<int> V(n);
	for (int i = 0; i < n; i++) {
		cin >> V[i];
		for (int j = 0; j < n; j++) {
			dp[i][j] = make_pair(-1,-1);
		}
	}
	solve(V, 0, n - 1);
	cout << dp[0][n - 1].first - dp[0][n - 1].second;
	
	return 0;
}
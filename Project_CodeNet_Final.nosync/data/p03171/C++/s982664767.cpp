#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string.h>
#include <map>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>
#include <math.h>
#include <time.h>
#include <assert.h>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <ll,ll>
#define N 100005
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;

ll dp[3001][3001][2];
int main()
{
	int n, l, r, A[N];
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
		dp[i][i][0] = A[i];
		dp[i][i][1] = -A[i];
	}
	for (int len = 2; len <= n; ++len)
	{
		for (int st = 1; st <= n - len + 1; ++st)
		{
			l = st;
			r = st + len - 1;
			dp[l][r][0] = max(A[l] + dp[l + 1][r][1], A[r] + dp[l][r - 1][1]);
			dp[l][r][1] = min(-A[l] + dp[l + 1][r][0], -A[r] + dp[l][r - 1][0]);
		}
	}
	cout << dp[1][n][0]; 
}

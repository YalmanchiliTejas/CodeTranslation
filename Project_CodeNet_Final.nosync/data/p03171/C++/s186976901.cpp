#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <string>
#include <memory.h>
#include <bitset>
#include <stack>
#include <assert.h>
using namespace std;
#define ll  long long
#define ld long double
#define ppi pair<ll, ll>
#define mp make_pair
const int N = 2e5 + 11, K = 20;
const int mod = 1e9 + 7;
int arr[N];
ll dp[3011][3011];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < n; i++)
		dp[i][i] = (n % 2 ? 1 : -1) * arr[i];

	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
		{
			ll lhs = dp[j + 1][n - i + j];
			ll rhs = dp[j][n - i + j - 1];
			if (i % 2) dp[j][n - i + j] = max(lhs + arr[j], rhs + arr[n - i + j]);
			else dp[j][n - i + j] = min(lhs - arr[j], rhs - arr[n - i + j]);
		}
	cout << dp[0][n - 1];
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;
#define show2(a, n, m) rep(i, n) { rep(j, m) {cout << a[i][j] << ' ';} cout << endl;} 

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

int main() {
//	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];

	vi dp(n + 1, -1);	// store the last number of each sequences
	dp[n - 1] = a[0];	// last number of 1st sequence
	dp[n] = INF;

	int cur = n - 1;
	for(int i = 1; i < n; i++) {
		int j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if(j == cur) dp[--cur] = a[i];	// can't add a[i] to existed sequence, so add a sequence
		else dp[j - 1] = a[i];	// update the last number of the sequence where a[i] is added
	}
	cout << n - cur << endl;
}

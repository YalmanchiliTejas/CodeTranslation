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
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl
#define show2(a, n, m) rep(i, n) { rep(j, m) {cout << a[i][j] << ' ';} cout << endl;} 
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

typedef vector<bool> vb;

int n;
vi a;
vector<vll> dp;
vector<vb> recorded;

ll rec(int l, int r) {
	if(recorded[l][r]) return dp[l][r];
	recorded[l][r] = true;
	bool first = (n - (r - l + 1)) % 2 == 0;
	if(l == r && first) return dp[l][r] = a[l];
	else if(l == r && !first) return dp[l][r] = -a[l];
	else if(first) return dp[l][r] = max(rec(l + 1, r) + a[l], rec(l, r - 1) + a[r]);
	else return dp[l][r] = min(rec(l + 1, r) - a[l], rec(l, r - 1) - a[r]);
}

int main() {
//	cout << fixed << setprecision(15);
	cin >> n;
	a = vi(n);
	rep(i, n) cin >> a[i];

	dp = vector<vll>(n, vll(n));
	recorded = vector<vb>(n, vb(n));
	ll b = (n % 2) ? 1 : -1;
	rep(i, n) {
		dp[i][i] = a[i] * b;
		recorded[i][i] = true;
	}
	cout << rec(0, n - 1) << endl;
}

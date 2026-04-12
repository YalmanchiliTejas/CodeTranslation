#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define ll long long
#define vi vector < int >
#define si set <int>
#define mii map <int, int>
#define vll vector < ll >
#define pii pair < int , int >
#define ff first
#define tc \
    int ttt; cin >> ttt;\
    while(ttt --)
#define ss second
#define f(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define nl '\n'
#define all(x) x.begin() , x.end()
#define mne min_element
#define mxe max_element
#define pr(x) cout << fixed << setprecision(10) << x
ll gcd(ll x, ll y) {return y == 0 ? x : gcd(y, x % y);}
int logg(ll x , ll y) {if (x == 0) return -1; return logg(x / y, y) + 1;}
ll poww(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll ans = 1;
	ans = poww(a, b >> 1, m);
	ans = (ans * ans) % m;
	if (b & 1) ans = (ans * a) % m;
	return ans;
}
// Start of code
int n;
int stones[100005];
int dp[3001][3001][2];
int X;
int Y;

int solve(int i, int j, int choice) {

	if (i > j) return 0;

	if (dp[i][j][choice] != -1) return dp[i][j][choice];

	if (choice) {
		dp[i][j][choice] = max(stones[i] + solve(i + 1, j, 0), stones[j] + solve(i, j - 1, 0));
	}
	else dp[i][j][choice] = min(solve(i + 1, j, 1), solve(i, j - 1, 1));

	return dp[i][j][choice];
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
	cin >> n;
	memset(dp , -1, sizeof dp);
	int sum = 0;
	f(i, 0, n) cin >> stones[i], sum += stones[i];
	X = solve(0, n - 1, 1);
	cout << X - (sum - X) << nl;
}
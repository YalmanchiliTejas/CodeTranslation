#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//<DEFINE>
void Fast() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}
void File() {
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#ifdef _WIN64
#define __builtin_popcountll __popcnt64
#else
inline int __builtin_popcountll(__int64 a) {
	return __builtin_popcount((unsigned int)a) + __builtin_popcount(a >> 32);
}
#endif
#endif
using ll = long long;
using ull = unsigned long long;
#define mod 1000000007
ll gcd(ll a, ll b) {
	return!b ? a : gcd(b, a % b);
}
#define fix(n) cout << fixed << setprecision(n);
#define all(a) a.begin(), a.end()
#define skip continue
#define stop(n) return cout<<n,0
#define pi  acos(-1)
#define endl "\n"
#define ceil(x,y) (x+y-1)/y
//sin(x* pi / 180)
//be careful from the multiplication while using this define 
//alot of memset may couse TLE
//</DEFINE>
int main() {
	Fast();
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<vector<vector<ll>>>dp(n, vector<vector<ll>>(n, vector<ll>(2)));
	for (int i = 0; i < n; i++)
		dp[i][i][1] = v[i], dp[i][i][0] = -v[i];
	for (int i = 1; i < n ; i++)
		for (int l = 0, r = i; r < n; r++, l++) {
			dp[l][r][0] = min(dp[l + 1][r][1] - v[l], dp[l][r - 1][1] - v[r]);
			dp[l][r][1] = max(dp[l + 1][r][0] + v[l], dp[l][r - 1][0] + v[r]);
		}
	cout << dp[0][n - 1][1] << endl;
}
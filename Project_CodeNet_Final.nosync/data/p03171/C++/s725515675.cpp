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
#define TC int t;cin>>t;while(t--)
int dx[] = { 0,0,-1,1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
//</DEFINE>
ll OO = 1e18;
ll dp[2][3000][3000];
int main() {
	Fast(), File();
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	for (int i = 0; i < n; i++)dp[1][i][i] = v[i], dp[0][i][i] = -v[i];
	for (int i = 1; i < n; i++) {
		int l = 0;
		for (int r = i; r < n; r++, l++) {
			dp[0][l][r] = OO, dp[1][l][r] = -OO;
			dp[0][l][r] = min(dp[1][l + 1][r] - v[l], dp[0][l][r]);
			dp[1][l][r] = max(dp[0][l + 1][r] + v[l], dp[1][l][r]);
			dp[0][l][r] = min(dp[1][l][r - 1] - v[r], dp[0][l][r]);
			dp[1][l][r] = max(dp[0][l][r - 1] + v[r], dp[1][l][r]);
		}
	}
	cout << dp[1][0][n - 1] << endl;
}
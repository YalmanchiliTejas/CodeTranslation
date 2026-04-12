#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
ll dp[3005][3005], a[3005];

ll rec(int len, int i) {
	int j = i + len;
	if (dp[i][j] != -1) return dp[i][j];
	if (len == 0) return dp[i][j] = 0;

	ll res;
	if ((n - len) % 2 == 0) {
		res = max(a[i] + rec(len - 1, i + 1), a[j - 1] + rec(len - 1, i));
	}
	else {
		res = min(-a[i] + rec(len - 1, i + 1), -a[j - 1] + rec(len - 1, i));
	}
	return dp[i][j] = res;
}

int main() {
	cin >> n;
	rep (i, n) cin >> a[i];

	memset(dp, -1, sizeof(dp));

	cout << rec(n, 0) << endl;
	return 0;
}
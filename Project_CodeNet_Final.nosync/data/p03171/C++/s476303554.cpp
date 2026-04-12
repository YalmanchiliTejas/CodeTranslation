#define _CRT_SECURE_NO_DEPRECATE
#include<bits/stdc++.h>
#define Rint register int
#define MP make_pair
#define fi first
#define se second
#define PB push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii; // 注意必要时改类型
typedef vector<int> vi;
const int N = 3e3 + 3;
//dp[i][j]表示拓展到i,j区间的最大差值
ll n, a[N], dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifdef _DEBUG
	int tt = clock();
	// freopen("in.txt", "r", stdin);
#endif 
	cin >> n;
	for (Rint i = 0; i < n; ++i) 
		cin >> a[i];
	for (Rint L = n - 1; L >= 0; --L) {
		for (Rint R = L; R < n; ++R) {
			if (L == R) {
				dp[L][R] = a[L];
			}
			else {
				dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
			}
		}
	}
	cout << dp[0][n - 1] << endl;
	




#ifdef _DEBUG
	cerr << "\nTIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}

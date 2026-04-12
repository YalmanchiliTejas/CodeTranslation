#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 3005;

int n;
int a[N];
int memo[N][N];

int dp(int l, int r) {
	if (l == r) return a[l];
	if (l > r) return -1e18;
	int &ans = memo[l][r];
	if (ans != -1e18) return ans;
	ans = -dp(l + 1, r) + a[l];
	ans = max(ans, -dp(l, r - 1) + a[r]);
	return ans;
}

void solve() {
	int i, j, k, m, ans = 0, cnt = 0, sum = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			memo[i][j] = -1e18;
		}
	}
	cout << dp(0, n - 1);
	return ;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t; while (t--)
	solve();
	return 0;
}
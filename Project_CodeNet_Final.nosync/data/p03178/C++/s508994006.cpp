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

const int N = 10005;
const int mod = 1e9 + 7;

string k;
int d;
int memo[N][2][105];

int dp(int pos, bool last, int modpro) {
	if (pos == k.size()) {
		return (modpro == 0);
	}
	int &ans = memo[pos][last][modpro];
	if (ans != -1) {
		return ans;
	}
	int till = (last ? k[pos] - '0' : 9);
	ans = 0;
	for (int i = 0; i <= till; i++) {
		ans += dp(pos + 1, last && (i == k[pos] - '0'), (modpro + i) % d);
		ans %= mod;
	}
	return ans % mod;
}

void solve() {
	int i, j, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> k >> d;
	memset(memo, -1, sizeof(memo));
	cout << (dp(0, 1, 0) - 1 + mod) % mod;
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
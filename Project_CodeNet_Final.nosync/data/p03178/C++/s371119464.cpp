#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define ld 	 long double
#define F 	 first
#define S 	 second
#define P 	 pair<int,int>
#define pb 	 push_back
#define mod  1000000007
#define inf  1e18
#define endl '\n'
const int N = 1e4 + 5; //change it when needed
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
int cache[N][105][2];
string K;
int  D;
int dp(int pos, int d, int tight) {
	if (pos == K.size()) {
		return (d == 0);
	}
	int &ans = cache[pos][d][tight];
	if (ans != -1)
		return ans;
	int ub = ((tight == 1) ? K[pos] - '0' : 9);
	ans = 0;
	for (int i = 0; i <= ub; i++) {
		ans += dp(pos + 1, (d + i) % D, (tight & (i == ub)));
		ans %= mod;
	}

	return ans % mod;
}
void solve() {

	cin >> K >> D;
	memset(cache, -1, sizeof(cache));
	cout << (mod + dp(0, 0, 1) - 1) % mod;
	//last -1 is because of 00000000 case
	// I am adding it to my answer
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t; while (t--)
	solve();
	return 0;
}
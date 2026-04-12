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
int cache[N][105][2];
string K;
int  D;
int dp(int pos, int d, int tight) {
	int ub = (tight == 1) ? K[pos] - '0' : 9;
	if (pos == K.size() - 1) {
		int ans = 0;
		for (int i = 0; i <= ub; i++) {
			if (i % D == d) {
				ans++;
			}
		}
		return ans;
	}
	int &ans = cache[pos][d][tight];
	if (ans != -1)return ans;
	ans = 0;
	for (int i = 0; i <= ub; i++) {
		ans = (ans + dp(pos + 1, (D + d - i % D) % D, (tight & (i == ub)))) % mod;
	}
	return ans;
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
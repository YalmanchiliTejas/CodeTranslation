#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define inf 1e18
#define fo(i,y,n,inc)	for(int i=y;i<n+y;i+=inc)
#define cin(t) int t;cin>>t
#define w(t) while(t--)
#define nl cout<<endl;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ft(i) (i&(-1*i))
#define arrIn(arr,size)		for(int i=0;i<size;i++){cin>>arr[i];}
#define arrOut(arr,size,seperater)	for(int i=0;i<size;i++){cout<<arr[i]<<seperater;}
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int powmd(int a, int b) {
	if (b == 1)	return a;
	if (b == 0)	return 1;

	int half = powmd(a, b / 2);
	int ans = half * half;
	ans %= mod;
	if (b & 1) {
		ans *= a;
	}
	ans %= mod;
	return ans;
}

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int dp[10004][105][2];

int solve(string& k, int& d, int pos, int rem, int tight) {

	if (dp[pos][rem][tight] != -1)	return dp[pos][rem][tight];

	int up = (tight) ? (k[pos] - '0') : 9;
	int ans = 0;

	if (pos == k.length() - 1) {
		for (int i = 0; i <= up; i++) {
			if (rem == i % d)	ans++;
		}
		return dp[pos][rem][tight] = ans;
	}

	for (int i = 0; i <= up; i++) {
		ans += solve(k, d, pos + 1, (d + rem - (i % d)) % d, (tight and (i == (k[pos] - '0'))));
		ans %= mod;
	}
	return dp[pos][rem][tight] = ans;
}

int32_t main() {

	fastIO();

	string k;
	cin >> k;
	int d;
	cin >> d;
	memset(dp, -1, sizeof(dp));

	cout << (solve(k, d, 0, 0, 1) - 1 + mod) % mod << endl;

	return 0;
}

// cout << "Case #" << i << ": " << answer << endl;
#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setbits(x) __builtin_popcount(x)
#define zerobits(x) __builtin_ctz(x)
#define setbitsll(x) __builtin_popcountll(x)
#define zerobitsll(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef map<int,int> mii;

const int MOD = 1e9+7;
int dp[105][4][2];
string n;
int k;

int f (int pos,int cnt,int tight) {
	if (cnt > k) return 0;
	if (pos == n.size()) {
		if (cnt == k) return 1;
		else return 0;
	}
	if (dp[pos][cnt][tight] != -1) return dp[pos][cnt][tight];
	int limit = (tight)?n[pos]-'0':9;
	int ret = 0;
	for (int i = 0;i <= limit;++i) {
		int newTight = (n[pos]-'0' == i)?tight:0;
		ret += f(pos+1,(i != 0)+cnt,newTight);
	}
	dp[pos][cnt][tight] = ret;
	return ret;
}

void solve () {
	memset(dp,-1,sizeof(dp));
	cin >> n >> k;
	int res = f(0,0,1);
	cout << res << '\n';
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}


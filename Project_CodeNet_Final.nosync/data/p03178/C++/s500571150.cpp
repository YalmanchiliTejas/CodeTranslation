#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define all(v) v.begin(), v.end()
#define PB push_back
#define F first
#define S second

typedef unsigned long long llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const int INF = 1e9+10;
const ll MOD = 1e9+7;

int dp[10007][107][2];
string s; int d;

int calc(int pos, int mod, int f){
	if(pos == (int)s.size())
		return (mod==0);
	if(dp[pos][mod][f] != -1)
		return dp[pos][mod][f];
	int mx = (f ? 9 : s[pos]-'0');

	int res = 0;
	for(int i = 0; i <= mx; i++){
		int ff;
		if(i < s[pos]-'0') ff = 1;
		else ff = f;
		res = ((ll) res + 1LL*calc(pos+1, (mod+i)%d, ff)) % MOD;
	}
	return dp[pos][mod][f] = res;
}

void solve(){
	cin >> s;
	cin >> d;

	memset(dp, -1, sizeof(dp));

	cout << (calc(0, 0, 0)-1 + MOD) % MOD << '\n';

}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int t=1; //cin >> t;
	FOR(i, t){
	    solve();
	}

	return 0;
}
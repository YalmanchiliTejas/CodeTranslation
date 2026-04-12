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

ll dp[101][101][2];

ll solve(string& num, int pos, int sum, int f, int k){
	if(pos == (int) num.size())
		return sum == k;
	if(dp[pos][sum][f] != -1)
		return dp[pos][sum][f];
	if(sum > k)
		return dp[pos][sum][f] = 0;
	int mx = (f ? 9 : num[pos]-'0');
	int ret = 0;
	for(int i = 0; i < mx; i++)
		ret += solve(num, pos+1, sum + (i>0), 1, k);
	ret += solve(num, pos+1, sum + (mx>0), f, k);
	return dp[pos][sum][f] = ret;
}


int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	string n;
	int k;
	cin >> n >> k;

	memset(dp, -1, sizeof dp);
	cout << solve(n, 0, 0, 0, k) << '\n';

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][105][2];
ll K;
ll countInRangeUtil(ll pos, ll cnt, ll tight,vector<ll> num){
	if (pos == num.size()) {
		if (cnt == K)return 1;
		return 0;
	}
	if (dp[pos][cnt][tight] != -1)return dp[pos][cnt][tight];
	ll ans = 0;
	ll limit = (tight ? 9 : num[pos]);
	for (ll dig = 0; dig <= limit; dig++) {
		ll currCnt = cnt;
		if (dig != 0)currCnt++;
		ll currTight = tight;
		if (dig < num[pos])
			currTight = 1;
		ans += countInRangeUtil(pos + 1, currCnt,currTight, num);
	}
	return dp[pos][cnt][tight] = ans;
}
ll countInRange(string x){
	vector<ll> num;
	for(ll i=0;i<x.size();i++)num.push_back(x[i]-'0');
	memset(dp, -1, sizeof(dp));
	return countInRangeUtil(0, 0, 0, num);
}

int main(){
    string n;
	cin>>n>>K;
	cout << countInRange(n);
    return 0;
}

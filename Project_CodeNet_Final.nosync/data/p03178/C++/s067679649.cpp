#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<queue>

using namespace std;

#define mod 1000000007
#define ll long long 


string str;
int D;
int n;
ll dp[10001][101][2];

ll solve(int idx, int rem, int tight) {
	if(idx == n)
		return rem == 0;

	if(dp[idx][rem][tight] != -1)
		return dp[idx][rem][tight];	

	ll ans = 0;
	int d = str[idx] - '0';
	int limit = (tight == 1) ? d : 9;
	int new_tight, new_rem;
	

	for(int i = 0; i <= limit; i++) {
		
		new_rem = rem;
		new_rem += i;
		new_rem %= D;

		new_tight = ((tight) & (i >= d));

		ans += solve(idx + 1, new_rem, new_tight);
		ans %= mod;
	}

	return dp[idx][rem][tight] = ans%mod;
}


int main() {
	
	memset(dp, -1, sizeof(dp));
	cin>>str>>D;

	n = str.length();
	ll ans = solve(0, 0, 1)%mod;

	ans--;
	if(ans == -1)
		ans = mod - 1;
    cout<<ans<<endl;

}
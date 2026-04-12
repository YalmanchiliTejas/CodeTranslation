#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

const int N = int(2e5) + 10;
bool vis[N][2][3];
ll dp[N][2][3];
ll pref[2];
ll suf[2];
ll a[N];
const ll inf = ll(1e18);
int n;

ll solve(int i, int flag, int cnt){
	if(cnt > 2 || (cnt == 2 && (n & 1) == 0)){
		return -inf;
	}

	if(i == n){
		if(n & 1)
			return cnt >= 1 ? 0 : -inf;
		else
			return 0;
	}

	bool &v = vis[i][flag][cnt];
	ll &ans = dp[i][flag][cnt];

	if(v){
		return ans;
	}

	v = true;

	ans = -inf;

	if(flag){
		ans = solve(i + 1, 0, cnt) + a[i];
	}

	ans = max(ans, solve(i + 1, 1, cnt + flag));

	return ans;
}

int main(){
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i]);
	}

	printf("%lld\n", solve(0, 1, 0));	

	return 0;
}
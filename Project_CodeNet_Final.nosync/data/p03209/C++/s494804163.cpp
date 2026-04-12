#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll n,x;
ll l[60];
ll dp[60];

ll solve(ll a, ll b){
	//cout << a << " " << b << endl;
	if(b == 0){
		return 0;
	}
	if(a == 0){
		return 1;
	}
	if(b >= l[a]/2+1){
		if(dp[a-1] != 0) return 1+dp[a-1]+solve(a-1,min(b-(l[a]/2+1),l[a-1]));
		else { dp[a-1] = solve(a-1,l[a-1]); return 1+dp[a-1]+solve(a-1,min(b-(l[a]/2+1),l[a-1]));}
	}else{
		return solve(a-1,min(l[a-1],b-1));
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> x;

	l[0] = 1;
	for (int i = 1;i <= n;i++){
		l[i] = l[i-1]*2+3;
	}

	cout << solve(n,x) << endl;

	return 0;

}

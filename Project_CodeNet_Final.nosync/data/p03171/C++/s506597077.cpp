#include <bits/stdc++.h>
using namespace std;

long long n, a[3010], dp[3010][3010];

long long func(int l, int r){
//	cout << l << " " << r << "\n";
	if(dp[l][r] != -1) return dp[l][r];
	if(l > r) return 0;
	long long res = 0;
	if((r - l) % 2 != n % 2){
		res = max(a[l] + func(l+1, r), a[r] + func(l, r-1));
	}else{
		res = min(-a[l] + func(l+1, r), -a[r] + func(l, r-1));
	}
//	cout << l << " " << r << " " << res << "\n";
	return dp[l][r] = res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i];
	int l = 0, r = n-1;
	memset(dp, -1, sizeof(dp));
	cout << func(l, r) << "\n";
}
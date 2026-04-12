#include <bits/stdc++.h>
using namespace std;

const int mex = 3005;
vector< vector<long long> > dp(mex, vector<long long>(mex, 0));
long long func(vector<int> &a , int l, int r){
	if(dp[l][r] == 0){
		if(l == r){
			return a[l];
		}
		else if(abs(l-r) == 1){
			return max(a[l], a[r]);
		}
		else{
			dp[l][r] = max(a[l]+min(func(a, l+1, r-1), func(a, l+2, r)), a[r] + min(func(a,l, r-2), func(a, l+1, r-1) ) );
			return dp[l][r];
		}
	}
	else
		return dp[l][r];
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	long long sum = 0;
	for(int i = 1; i<=n ; i++){
		cin >> a[i];
		sum += a[i];
	}
	
	long long res = func(a, 1, n);
	cout<<(2*res-sum)<<endl;
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long n, sum[3005], a[3005], dp[3005][3005], v[3005][3005];
long long solve (int l, int r){
	if (l==r) return a[l]; if (v[l][r]) return dp[l][r]; v[l][r]=1; 
	dp[l][r] = max(a[l]+(sum[r]-sum[l]-solve(l+1, r)), a[r]+(sum[r-1]-sum[l-1]-solve(l, r-1)));
	return dp[l][r];
}
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n;
for (int i=1; i<=n; i++){
	cin >> a[i]; 
	sum[i]=a[i]+sum[i-1];
}
cout << 2*solve(1, n)-sum[n];
return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF= 1e18L+5;

int main() {
	int n;
	cin >>n;
	ll a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	ll dp[n+1][n+1];

	for(int r=0; r<n;r++){
		for(int l=r;l>=0;l--){
			if(l==r)
				dp[l][r] = a[l];
			else{
				dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
}
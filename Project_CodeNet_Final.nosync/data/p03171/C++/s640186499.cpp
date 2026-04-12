#include <bits/stdc++.h>
using namespace std;
int n,arr[3009];
long long dp[3009][3009];
long long bt(int l,int r){
	if(l == r) return arr[l];
	long long &ret = dp[l][r];
	if(ret != -1000000000000009ll) return ret;
	ret = max(arr[l]-bt(l+1,r),arr[r]-bt(l,r-1));
	return ret;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<3001;i++){
		for(int j=0;j<3001;j++) dp[i][j] = -1000000000000009ll;
	}
	cout<<bt(0,n-1)<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[3009];
long long dp[3009][3009];
long long bt(int l,int r){
	if(l == r){
		return arr[l];
	}
	long long &ret = dp[l][r];
	if(ret != -100000000000000009ll)return ret;
	ret = max(arr[l] - bt(l+1,r), arr[r] - bt(l,r-1));
	return ret;
}
int main(){
	for(int i=0;i<=3000;i++){
		for(int j=0;j<=3000;j++){
			dp[i][j] = -100000000000000009ll;
		}
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<bt(0,n-1)<<endl;
}

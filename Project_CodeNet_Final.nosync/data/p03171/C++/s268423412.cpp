#include <iostream>
#include <cstring>
using namespace std;

long long int n, arr[3001], dp[3001][3001][2];

long long int recursive(int l, int r, int tur){
	if(dp[l][r][tur]!=-1)return dp[l][r][tur];
	if(l==r&&tur==1)return arr[l];
	if(l==r&&tur==2)return -arr[l];
	if(tur==1)dp[l][r][tur]=max(recursive(l+1, r, 2)+ arr[l], recursive(l, r-1, 2)+arr[r]);
	if(tur==2)dp[l][r][tur]=min(recursive(l+1, r, 1)-arr[l] , recursive(l, r-1, 1)-arr[r]);
	return dp[l][r][tur];
}


int main(void){
	cin>>n;
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<recursive(0, n-1, 1);

	return 0;
}
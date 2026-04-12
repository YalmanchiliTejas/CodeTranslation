#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int llint;
llint arr[3005],dp[3005][3005][2];
llint rek(int l,int r,llint x,llint y,int a) {
	if(l>r) return 0;
	if(dp[l][r][a]!=-1) return dp[l][r][a];
	llint ret;
	if(a==0) ret=max(rek(l+1,r,x+arr[l],y,1)+arr[l],rek(l,r-1,x+arr[r],y,1)+arr[r]);
	else ret=min(rek(l+1,r,x,y+arr[l],0)-arr[l],rek(l,r-1,x,y+arr[r],0)-arr[r]);
	dp[l][r][a]=ret;
	//cout <<l<<" "<<r<<" "<<a<<" "<<x<<" "<<y<<" "<<ret<<endl;
	return ret;
}
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	memset(dp,-1,sizeof(dp));
	/*for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			if(i==j) dp[i][j]=
		}
	}*/
	cout <<rek(0,n-1,0,0,0);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
#define f(x,y,z) for(int x=(y),__=(z);x<=__;++x)
typedef long long ll;
#define v64 vector<ll>
//dp[i][j]：到第i个，j==1：选择此个，j==0：不选择此个，到此共选择了i/2个，得到的最大值。
/* 转移方程：
 
i为奇数时
选择(i-1)/2个 
dp[i][1]= arr[i]+max{dp[i-2][0],dp[i-2][1],dp[i-3][1],dp[i-3][0]}

dp[i][0]= max{dp[i-2][0]+arr[i-1],dp[i-3][1]+arr[i-1],dp[i-3][0]+arr[i-2],dp[i-3][0]+arr[i-1]} 
i为偶数时

*/ 
ll dp[maxn][2];
int main(){
	int n;
	scanf("%d",&n);
	v64 arr(n+1,0);
	f(i,1,n)
		cin >> arr[i];
	dp[2][1]=arr[2];
	dp[2][0]=arr[1];
	f(i,3,n){
		if(i&1){
			dp[i][1]=arr[i]+max(dp[i-2][0],dp[i-2][1]);
			dp[i][0]=max(arr[i-2]+dp[i-3][0],arr[i-1]+dp[i-2][0]);
		}
		else{
			dp[i][1]=arr[i]+dp[i-1][0];
			dp[i][0]=arr[i-1]+dp[i-2][0];
		}
	}
	printf("%lld\n",max(dp[n][1],dp[n][0]));
}
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#define PI acos(-1)
#define pb push_back
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define dd(x) cout<<#x<<" = "<<x<<","
#define de(x) cout<<#x<<" = "<<x<<"\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
const int M=4;
int a[N];
ll dp[N][M]; 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<M;j++){
			dp[i][j]=-1e17;
		}
	}
	if(n==2){
		printf("%d",max(a[1],a[2]));
		return 0;
	}
	if(n&1){
		dp[1][2]=a[1];
		dp[2][1]=a[2];
		dp[3][0]=a[3];
		for(int i=3;i<=n;i++){
			dp[i][0]=max(dp[i][0],dp[i-2][0]+a[i]);
			if(i>3)
			dp[i][0]=max(dp[i][0],dp[i-3][1]+a[i]);
			if(i>4)
			dp[i][0]=max(dp[i][0],dp[i-4][2]+a[i]);
			
			dp[i][1]=max(dp[i][1],dp[i-2][1]+a[i]);
			if(i>3)
			dp[i][1]=max(dp[i][1],dp[i-3][2]+a[i]);
			
			dp[i][2]=max(dp[i][2],dp[i-2][2]+a[i]);
			
		}
		printf("%lld",max(max(dp[n][0],dp[n-1][1]),dp[n-2][2]));
	}
	else{
		dp[1][1]=a[1];
		dp[2][0]=a[2];
		for(int i=3;i<=n;i++){
			dp[i][0]=max(dp[i][0],dp[i-2][0]+a[i]);
			if(i>3)
			dp[i][0]=max(dp[i][0],dp[i-3][1]+a[i]);
			dp[i][1]=max(dp[i][1],dp[i-2][1]+a[i]);
		}
		printf("%lld",max(dp[n][0],dp[n-1][1]));
	} 
}

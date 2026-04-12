#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[3005];
long long memo[3005][3005];

long long dp(int p,int x,int y){
	if(x>y)return 0;
	if(x==y){
		if(p==0)return arr[x];
		else return -arr[x];
	}
	if(memo[x][y]!=-1)return memo[x][y];
	if(p==0){
		return memo[x][y]=max(dp(1,x+1,y)+arr[x],dp(1,x,y-1)+arr[y]);
	}else{
		return memo[x][y]=min(dp(0,x+1,y)-arr[x],dp(0,x,y-1)-arr[y]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&arr[i]);
	memset(memo,-1,sizeof(memo));
	printf("%lld",dp(0,0,n-1));
}

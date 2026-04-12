#include <bits/stdc++.h>

using namespace std;

int arr[3003];

/*void pre(int n){
	for(int i = 2; i<=n; ++i){
    	arr[i]+=arr[i-1];
    }
}

int getscore(int l, int r){
	return arr[r]-arr[l-1];
}*/

long long dp[3003][3003];
int vis[3003][3003];

long long solve(int i, int j){
	if(i==j){
      	return dp[i][j] = arr[i];
    }
  	if(i>j)return 0;
  	if(vis[i][j])return dp[i][j];
  	
  	vis[i][j] = 1;
  
    long long x1 = arr[i];
  	long long x1y1 = arr[i+1];
  	long long ret1 = (x1-x1y1)+solve(i+2,j);
  	long long x1y2 = arr[j];
  	long long ret2 = (x1-x1y2)+solve(i+1,j-1);
  //cout<<"ret1: "<<ret1<<" ret2: "<<ret2<<"\n";
  	long long r1 = min(ret1,ret2);
  //cout<<"r1: "<<r1<<"\n";
  	
    long long x2 = arr[j];
  	long long x2y1 = arr[i];
  	ret1 = (x2-x2y1)+solve(i+1,j-1);
  	long long x2y2 = arr[j-1];
  	ret2 = (x2-x2y2)+solve(i,j-2);
  // cout<<"ret1: "<<ret1<<" ret2: "<<ret2<<"\n";
  	long long r2 = min(ret1,ret2);
   // cout<<"r2: "<<r2<<"\n";
  	return dp[i][j] = max(r1,r2);
  	
}

int main(){
	int n;
  	scanf("%d",&n);
  	for(int i = 1; i<=n; ++i)
      	scanf("%d",&arr[i]);
  	//pre(n);
  	memset(vis,0,sizeof(vis));
    long long ans = solve(1,n);
  	printf("%lld\n",ans);
  	return 0;
}
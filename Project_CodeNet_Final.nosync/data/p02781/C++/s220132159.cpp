#include<bits/stdc++.h>

using namespace std;
#define int long long
string n;
int k;

int dp[105][105][2];

int count(int x,int nz,int t){
	if(x==n.size()){
		if(nz==k)
			return 1;
		return 0;
	}
	if(dp[x][nz][t]!=-1)
		return dp[x][nz][t];
	int c=0,m=9;
	if(t){
		m=n[x]-'0';
	}
	for(int i=0;i<=m;i++){
		if(i!=0){
			c+=count(x+1,nz+1,(t&&(i==m)?1:0));
		}
		else
			c+=count(x+1,nz,(t&&(i==m)?1:0));
	}
	return dp[x][nz][t]=c;
}

signed main(){
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	cout<<count(0,0,1);
}

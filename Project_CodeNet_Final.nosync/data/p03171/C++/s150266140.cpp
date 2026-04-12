#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN=4096;
LL dp[MAXN][MAXN],a[MAXN];
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l<n;l++){
			int r=l+len-1;
			if(r>n) break;
			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}

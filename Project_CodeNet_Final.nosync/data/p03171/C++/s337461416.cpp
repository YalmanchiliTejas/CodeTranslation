#include <bits/stdc++.h>
using namespace std;
long long n;
long long dp[3001][3001];

long long func(long long i,long long j,long long *a,long long total){
    if(i==j){
        return a[i];
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]= max(total-func(i+1,j,a,total-a[i]),total-func(i,j-1,a,total-a[j]));
    return dp[i][j];
}

int main() {
	long long n;
	
	cin>>n;
	memset(dp,-1,sizeof(dp));
	long long a[n+1];
	long long total=0;
	for(long long i=1;i<=n;i++){
	    cin>>a[i];
	    total+=a[i];
	}
	cout<<2*func(1,n,a,total)-total;
    
}

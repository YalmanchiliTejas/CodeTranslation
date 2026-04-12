#include <iostream>
using namespace std;

long long dp[3002][3002], a[3002];

int n ;
long long solve(int i, int j) {
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int l = j -i  + 1;
    if(l%2==n%2) { //taro
        return dp[i][j]=max(solve(i+1, j) + a[i], a[j] + solve(i, j-1));
    } else { // jiro
        return dp[i][j]=min(solve(i+1, j) - a[i], -a[j] + solve(i, j-1));
    }
}
int main() {
	int i, j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	
	for(i=1;i<=n;i++) 
	    for(j=1;j<=n;j++)
	        dp[i][j] = -1;
	long long ans = solve(1, n);
	cout<<ans<<"\n";
	return 0;
}
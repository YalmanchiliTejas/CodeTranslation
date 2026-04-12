#include <bits/stdc++.h>
using namespace std;
#define lli long long
lli dp[3002][3002];
lli a[3002];
const lli INF = (lli)(3e14);
int n;

lli solve(int i, int j) {
    
    //cout<<"i and j "<<i<<" "<<j<<endl;
    
    if(i>=n || j>=n || i<0 || j<0) return 0;
    
    if(i==j) return dp[i][j] = a[i];
    
    if(i>j) return dp[i][j] = 0;
    
    if(dp[i][j]!=INF) return dp[i][j];
    
    return dp[i][j] = max(a[i] - solve(i+1,j), a[j] - solve(i,j-1));
}

int main() 
{
    cin >> n;
    lli sum = 0;
    
    for(int i=0;i<n;i++) {cin >> a[i]; sum+=a[i];}
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) dp[i][j] = INF;
    }
    
    lli X = solve(0,n-1);
	
	cout<<X<<endl;
	
	return 0;
}
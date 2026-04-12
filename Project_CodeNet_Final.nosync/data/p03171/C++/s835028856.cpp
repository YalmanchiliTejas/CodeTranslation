#include <bits/stdc++.h>

using namespace std;

long long dp[3001][3001];

long long solve(vector<long long>& points ,int i ,int j){
    if(i==j)
        return points[i];
    if(i+1==j)
        return max(points[i],points[j]);
        
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    long long start = points[i] + min(solve(points,i+2,j),solve(points,i+1,j-1));
    long long end = points[j] + min(solve(points,i+1,j-1),solve(points,i,j-2));
    
    return dp[i][j] = max(start,end);
}

int main() {
	// your code goes here
	int n ;
	cin>>n;
	vector<long long> points(n+1);
	long long sum =0;
	for(int i=1;i<=n;i++){
	    cin>>points[i];
	    sum+=points[i];
	}
	memset(dp,-1,sizeof(dp));
	long long x = solve(points,1,n);
	long long y = (sum - x);
	cout<<(x-y)<<endl;
	return 0;
}

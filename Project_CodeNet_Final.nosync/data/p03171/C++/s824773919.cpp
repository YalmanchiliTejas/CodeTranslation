#include <iostream>
#include <vector>
#define INF 1e18
using namespace std;

vector<vector<long long>>dp;

long long dp_func(int arr[], int i, int j)
{
    
    if(i==j)
        return dp[i][j]=arr[i];
    
    if(dp[i][j]!=INF)
    return dp[i][j];
    long long ans=0;
    
    ans = max((long long)arr[i]-dp_func(arr,i+1,j), (long long)arr[j]-dp_func(arr,i,j-1));
    return dp[i][j]=ans;
    
}

int main() {
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
    	cin>>arr[i];
	
	dp.assign(n,vector<long long>(n,INF));
	
	cout<<dp_func(arr,0,n-1);
	
	return 0;
}
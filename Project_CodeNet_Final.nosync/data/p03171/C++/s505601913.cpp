#include <iostream>
using namespace std;

int main() {
	//code
	
	    int n,i,j,gap=0;
	    cin>>n;
	    long long A[n],sum=0;
	    for(i=0;i<n;i++)
        {
          cin>>A[i];
          sum+=A[i];
        }
	    long long dp[n][n];    
	    for(i=0;i<n;i++)
	        dp[i][i]=A[i];
	    for(i=0;i<n-1;i++)
	        dp[i][i+1]=max(A[i],A[i+1]);
	    for(i=0;i<n-2;i++)
	        dp[i][i+2]=max(A[i]+min(A[i+1],A[i+2]),A[i+2]+min(A[i],A[i+1]));
	        
	    for(gap=4;gap<=n;gap++)
	    {
	        for(i=0;i<=n-gap;i++)
	        {
	            j=i+gap-1;
	            dp[i][j] = max(A[i]+min(dp[i+1][j-1],dp[i+2][j]),
	                           A[j]+min(dp[i+1][j-1],dp[i][j-2])); 
	        }
	    }
	    
	    cout<<2*dp[0][n-1]-sum<<endl;
	
	return 0;
}
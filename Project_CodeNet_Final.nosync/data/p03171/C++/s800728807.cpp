#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
		int n;
	    cin>>n; int sum=0;
	    vector<int> A(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>A[i];
	        sum+=A[i];
	    }
	    vector<vector<int>> dp(n,vector<int>(n));
	    for(int i=0;i<n;i++)
	    	dp[i][i]=A[i];
	    for(int gap=1;gap<n;gap++)
	    {
	        for(int i=0,j=gap;j<n;j++,i++)
	        {
	            int x=(i+2<=j)?dp[i+2][j]:0;
	            int y=(i+1<=j-1)?dp[i+1][j-1]:0;
	            int z=(i<=j-2)?dp[i][j-2]:0;
	            dp[i][j]=max(A[i] + min(x, y), A[j] + min(y, z));
	        }
	        
	    }
	    int X=dp[0][n-1];
	    cout<<2*X-sum<<endl;
	
}	
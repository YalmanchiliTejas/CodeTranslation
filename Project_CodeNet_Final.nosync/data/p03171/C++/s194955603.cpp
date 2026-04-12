#include <bits/stdc++.h>

using namespace std;

long long int dp[3001][3001][2];

long long int solve(long int a[], int i,int j,int t)
{
    if(i==j)
    {
        return 0;
    }
	else if(dp[i][j][t]!=-1)
	{
		return dp[i][j][t];
	}
    else if(t==1)
    {
        dp[i][j][t] = max(solve(a,i+1,j,0)+a[i], solve(a, i,j-1,0)+a[j-1]);
    }
    else
    {
        dp[i][j][t] = min(solve(a, i+1,j,1)-a[i],solve(a, i,j-1,1)-a[j-1]);
    }
    
    return dp[i][j][t];
}

int main()
{
    int n;
    cin>>n;
    long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
	
    memset(dp, -1, sizeof(dp[0][0][0]) * 3001 * 3001 * 2);
				
    cout<<solve(a,0,n,1);

    return 0;
    

}
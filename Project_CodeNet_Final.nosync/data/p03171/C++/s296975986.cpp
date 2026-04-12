#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<set>
using namespace std;

void itsvgg() 
{
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
} 

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	
    itsvgg();
	
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    	cin>>a[i];
    long long int dp[n+1][n+1];

    for(int i=n-1;i>-1;i--)
    {
    	for(int j=i;j<n;j++)
    	{
    		if(i==j)
    			dp[i][j]=a[i];
    		else
    		{
                dp[i][j]=max((a[i]-dp[i+1][j]),(a[j]-dp[i][j-1]));
    		}

    	}
    	//cout<<dp[i][n-1]<<endl;

    }



    cout<<dp[0][n-1]<<endl;


}

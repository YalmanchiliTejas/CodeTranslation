#include<bits/stdc++.h>
using namespace std;
long long int dp[10000][100];
long long int dp2[10000][100];
int mod=1000000007;
int main()
{
	string s;
	cin>>s;
	int d;
	cin>>d;
	
	int n=s.size();
	//cout<<n<<endl;
	long long int ans=0;
	long long int ans2=0;
     if(n==1)
     {
      for (int i = 0; i <=9; ++i)
    {
    	if(s[n-1]-'0'>=i)
    	{
    		dp2[n-1][i%d]++;
    	}
    }
    cout<<dp2[n-1][0]-1<<endl;
}
else
{

     
	for (int i = 0; i <=9; ++i)
    {
    	dp[n-1][i%d]++;
    	
    }

    ans+=(dp[n-1][0]-1);
    
    
    	
    
    
    

    

    for (int i =n-2; i>=1; --i)
    {
    	for (int j = 0; j <=9; ++j)
    	{

    		for (int k = 0; k < d; ++k)
    		{
    			if(dp[i+1][k]>0)
    			{
    				dp[i][(k+j)%d]=(dp[i][(k+j)%d] + dp[i+1][k])%mod;

    			}
    			
    			
    		}

    	}
    	
    }
   
    for (int i = n-1; i>=2; --i)
    {
    	ans2=(ans2+dp[i][0])%mod;
    }

    
    for (int i =n-2; i>=1; --i)
    {
    	//cout<<dp[i][0]<<endl;
    	ans+=(dp[i][0]);
    }
   
    ans=(ans-ans2);
    ans=(ans+mod)%mod;
   
    for (int i = 0; i <=9; ++i)
    {
    	if(s[n-1]-'0'>=i)
    	{
    		dp2[n-1][i%d]++;
    	}
    }
    
	for (int i =n-2; i >=0 ; --i)
	{
		for (int j = 0; j <=9; ++j)
		{
			if(s[i]-'0'<j)
				break;
			if(i==0 && j==0)
				continue;
			else if(s[i]-'0'>j)
			{
				
				for (int k = 0; k < d; ++k)
				{
					if(dp[i+1][k]>0)
					  dp2[i][(k+j)%d]=(dp2[i][(k+j)%d]+dp[i+1][k])%mod;
				}
			}
			else
			{
				for (int k = 0; k < d; ++k)
				{
				    if(dp2[i+1][k]>0)
				    	dp2[i][(k+j)%d]=(dp2[i+1][k] + dp2[i][(k+j)%d])%mod;
				}

			}
		}
		
	}


	
	ans=(ans+dp2[0][0])%mod;
	cout<<ans<<endl;
	
}
	
    

}
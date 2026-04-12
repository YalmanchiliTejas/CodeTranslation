#include <bits/stdc++.h>
using namespace std;

long long int arr[3005];
long long int dp[3005][3005];
int n;
long long int call(int i,int j)
{
	 
	   
	 if(j==i+1)
	 return max(arr[j],arr[i]);
	 
	 if(j==i)
	  return arr[i];
	  
	  if(dp[i][j]!=-1)
	   return dp[i][j];
	   
	return dp[i][j]=max(arr[i]+min(call(i+2,j),call(i+1,j-1)),arr[j]+min(call(i,j-2),call(i+1,j-1)));
}

 int main()
{ 
    
     cin>>n;
     long long int sum=0;
     for(int i=0;i<n;i++)
    {
	   cin>>arr[i];
       sum+=arr[i];
   }
       for(int i=0;i<=n;i++)
         for(int j=0;j<=n;j++)
          dp[i][j]=-1;
          
     cout<<2*call(0,n-1)-sum<<endl;  
       
     return 0;
}



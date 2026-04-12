#include<bits/stdc++.h>
using namespace std;

#define mod  1000000007
int main()
{
	
   int n; cin>>n;
   long long a[n];
   long long pre[n+2]; long long pre2[n+2],pre3[n+2];
   
   for( int i=0;i<n;i++) cin>>a[i];
   long long sum=0;
   
   for ( int i=0;i<=n;i++) pre[i]=0,pre2[i]=0,pre3[i]=0;
   
    for ( int i=1;i<=n;i++)
    {
    	pre[i]= pre[i-1]+ a[i-1];
    	
    	
	}
	

	
	for( int i=1;i<=n;i++)
	{
		pre2[i]= pre[n]-pre[i];

		
	
		pre2[i]=pre2[i]%mod; 
		a[i-1]= a[i-1]%mod ;
		
	     pre2[i]= pre2[i]*a[i-1];
		 
	    	pre2[i]= pre2[i]%mod;
	}
	
	for( int i=1;i<=n;i++)
	{
		sum= sum + pre2[i];
		sum= sum%mod ;
	}
	
	
   
   
   cout<<sum<<endl;
   
   
			
		

	
	
	
}
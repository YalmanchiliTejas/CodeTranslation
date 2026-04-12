#include<iostream>
using namespace std;
#include<iomanip>
#include<map>
#define mod 998244353
#define int long long int
int memo[3005][3005];
int function(int arr[],int initial,int final,int s,int sum)
{
	if(sum==s)
	{
		return final-initial+2;
	}
    if(sum>s)
       return 0;
	if(initial>final)
	{
		   return 0;
	}
	if(memo[initial][sum]!=-1)
	    return memo[initial][sum];
	else
	{
		int x=function(arr,initial+1,final,s,sum+arr[initial]);
		int y=function(arr,initial+1,final,s,sum);
		memo[initial][sum]=(x+y)%mod;
		return memo[initial][sum];
	}
}
int32_t main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
     int i,j;
     int n;
     cin>>n;
     int s;
     cin>>s;
     int arr[n];
     for(j=0;j<n;j++)
         cin>>arr[j];
     for(i=0;i<=3004;i++)
     {
		 for(j=0;j<=3004;j++)
		 {
			 memo[i][j]=-1;
		 }
	 }
	 int answer=0;
	 for(j=0;j<n;j++)
	 {
		 answer=answer+function(arr,j,n-1,s,0);
		 answer=answer%mod;
	 }
	 cout<<answer<<endl;
}

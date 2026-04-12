#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pq priority_queue<int> 
#define pqs priority_queue<int,vector<int>, greater<int>>
#define setbits(x) __builtin_popcountll(x)  // no of ones in setbit
#define zrobits(x) __builtin_ctzll(x)       //101000 here 3..no of 0 aftrer 1sr right one 
#define mod 1000000007
#define inf 1e18
#define prDouble(x)  cout<<fixed<<setprecision(10)<<x     // ans upto 5 decimal place 
#define mk(ar,n,type) type *arr=new type[n];
#define w(x) int x;cin>>x;while(x--)
int dp[3001][3001] ;  



int fn(int arr[], int i , int j )
{

	if(i==j)
	{
		return arr[i] ; 
	}
	if(i>j)
	{
		return 0 ; 
	}

	if(dp[i][j] !=-1 )
	{
		return dp[i][j] ; 
	}

	int a=min(arr[i]+fn(arr,i+1,j-1) , arr[i]+fn(arr,i+2,j) ) ; 
	int b=min(arr[j]+fn(arr,i+1,j-1), arr[j]+fn(arr,i,j-2) ) ; 

	return dp[i][j]= max(a, b) ; 

}


int32_t main()
{
	int n; 
	cin>>n; 
	int arr[n+1];
	int s=0 ; 
	for(int i=0 ; i<n; i++)
	{
		cin>>arr[i] ; 
		s=s+arr[i] ; 
	}
	memset(dp, -1, sizeof(dp)) ; 
	int x=fn(arr, 0, n-1);
	int y=(s-x) ; 
	cout<<(x-y) ; 

}
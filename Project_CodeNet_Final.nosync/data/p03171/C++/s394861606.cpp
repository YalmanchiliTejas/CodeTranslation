#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int dp[3001][3001];
long long int f(long long int arr[],int i,int j,int n)
{
    if(i>j)return 0;
    if(dp[i][j]!=-9999999999)
    return dp[i][j];
   if(!((n-j+i-1)&1)){
		return  dp[i][j]=max(f(arr,i+1,j,n)+arr[i],f(arr,i,j-1,n)+arr[j]);
	}else{
		return dp[i][j]=min(f(arr,i+1,j,n)-arr[i],f(arr,i,j-1,n)-arr[j]);
	}
}

int main() {
	int n,j;
	cin>>n;
	long long int arr[n]={0};
	int i; 
	for(i=0;i<n;i++)
	cin>>arr[i];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	    dp[i][j]=-9999999999;
	}
	long long int x=f(arr,0,n-1,n);
	cout<<x;
	return 0;
	
}

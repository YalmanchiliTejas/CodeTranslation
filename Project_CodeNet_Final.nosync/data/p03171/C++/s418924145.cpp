#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int dp[3001][3001];
long long int f(long long int arr[],int i,int j)
{
    if(i>j)return 0;
    if(dp[i][j]!=-9999999999)
    return dp[i][j];
    else
    return dp[i][j]= max(arr[j]-f(arr,i,j-1),arr[i]-f(arr,i+1,j));
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
	long long int x=f(arr,0,n-1);
	cout<<x;
	return 0;
	
}

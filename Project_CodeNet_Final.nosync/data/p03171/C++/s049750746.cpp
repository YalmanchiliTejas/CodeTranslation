#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
long long int solve(long long int *arr,long long int n,long long int back,long long int front,long long int **dp)
{
    if(front<back)
    {
        return 0;
    }
    if(dp[back][front]!=0)
    {
        return dp[back][front];
    }
    
    long long int a = arr[back] + min(solve(arr,n,back+2,front,dp),solve(arr,n,back+1,front-1,dp));
    
    long long int b =arr[front]+min(solve(arr,n,back,front-2,dp),solve(arr,n,back+1,front-1,dp));
    
    long long int ans =max(a,b);
    dp[back][front]=ans;
   // cout<<front<<back<<" ans is"<<ans<<endl;
    return ans;
}
 int main()
{
    long long int t;
    cin>>t;
   
    long long int* arr = new long long int[t];
    
    long long int **dp=new long long int*[t];
    for(long long int l=0;l<t;l++)
    {
        dp[l]=new long long int[t]{0};
    }
    long long int sum =0;
    for(long long int i=0;i<t;i++)
    {
        cin>>arr[i];
        sum =sum+arr[i];
    }
   
    long long int k = solve(arr,t,0,t-1,dp);
    cout<<2*k-sum;

    return 0;
}
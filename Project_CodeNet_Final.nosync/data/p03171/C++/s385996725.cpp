#include <iostream>
#include <cmath>
#include <vector>
#include<bits/stdc++.h> 
#include<cstring>
#include<utility>
#define ll long long
using namespace std;
 
 ll mx(vector<ll> &A, vector<vector<ll> > &dp, int i, int j)
 {
 	if(dp[i][j]!=-1) return dp[i][j];
 	if(i==j) dp[i][j]= A[i];
 	else if(i==j-1) dp[i][j] = max(A[i], A[j]);
 	else dp[i][j] = max(A[i] + min(mx(A, dp, i+2, j), mx(A, dp, i+1, j-1)), 
	 A[j] + min(mx(A, dp, i, j-2),mx(A, dp, i+1, j-1) ));
	 
	 return dp[i][j];
 }
int main()
{
   int n;
   cin>>n;
   vector<ll> A;
   for(int i =0;i<n;i++)
   {
   	int a;
   	cin>>a;
   	A.push_back(a);
   }
   vector<vector<ll> > dp;
   vector<ll> temp;
   for(int i =0;i<n;i++)
   temp.push_back(-1);
   
   for(int i =0;i<n;i++)
   dp.push_back(temp);
   
   ll x = mx(A, dp, 0, n-1);
   ll sum=0;
   for(int i =0;i<n;i++)
   sum+=A[i];
   
   ll y = sum - x;
   
   cout<<x-y;
	return 0;
}
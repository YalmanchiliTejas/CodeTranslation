#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//vector<vector<int> > dp(500,vector<int> (500,-1));

long long int solve(vector<long long int> &A,int i, int j,vector<vector<long long int> > &dp){
    if(i+1==j){
        return max(A[i],A[j]);
    }
    if(i==j){
        return A[i];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = max(A[i]+min(solve(A,i+2,j,dp),solve(A,i+1,j-1,dp)),A[j]+min(solve(A,i,j-2,dp),solve(A,i+1,j-1,dp)));
    return dp[i][j];
}
int main(){
  int n;
  cin>>n;
  std::vector<long long int>A(n) ;
  long long int sum =0;
  for(int i=0;i<n;i++){
      cin>>A[i];
      sum+=A[i];
  }
  vector<vector<long long int> > dp(n,vector<long long int> (n,-1));
  long long int X = solve(A,0,n-1,dp);
  long long int Y = sum-X;
  std::cout << X-Y << std::endl;
  return 0;
}
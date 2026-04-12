// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
long long int dp[3010][3010];
long long int A[3010];
long long int solve(int i,int j){
  if(i>j){
    dp[i][j]=0;
    return dp[i][j];
  }
  if(dp[i][j]!=INT_MIN){
    return dp[i][j];
  }
  if(A[i]-solve(i+1,j) > A[j]-solve(i,j-1)){
    dp[i][j]=A[i]-solve(i+1,j);
    return dp[i][j];
  }else{
    dp[i][j]=A[j]-solve(i,j-1);
    return dp[i][j];
  }

}
int main(){
int n;
cin>>n;
 //long long int ans=0;
 //long long int A[n];
 for(int i=0;i<n;++i){
    cin >> A[i];
 }
 for(int i=0;i<n;++i){
    for(int j=0;j<n;++j)
        dp[i][j]=INT_MIN;
 }
 cout << solve(0,n-1)<<endl;
 return 0;

}

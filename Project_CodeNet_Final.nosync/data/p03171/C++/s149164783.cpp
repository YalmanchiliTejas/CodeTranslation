


#include <bits/stdc++.h>
using namespace std;


#define ll long long 
ll dp[3001][3001];
ll solve(ll a[],int i, int j){

    if(i>j){

        return 0;
        
    }

    if(dp[i][j]!=-1){
        return dp[i][j];

    }

    if(i==j){
        return a[i];
    }

    return dp[i][j]=max(a[i]+min(solve(a,i+2,j),solve(a,i+1,j-1)),a[j]+min(solve(a,i+1,j-1),solve(a,i,j-2)));

}

 
int main() {
   
   int n;
   cin>>n;

   ll a[n];
   ll sum=0;

   for(int i=0;i<n;i++){
       cin>>a[i];
       sum+=a[i];
   }
   
   memset(dp,-1,sizeof(dp));


   


   ll X=solve(a,0,n-1);
   ll Y=sum-X;
   cout<<(X-Y);






}

#include<bits/stdc++.h>
using namespace std;



int main(){
     int n;
     cin>>n;
     vector<int>v(n,0);
     vector<vector<long long>>dp(n,vector<long long>(n,0));
int c=0;
int x=0,y=0;
     for(int i=0;i<n;i++){
          cin>>v[i];
     }
     
     for(int i=0;i<n;i++){
          dp[i][i]=(long long)v[i];
     }
     
     for(int i=n-1;i>=0;i--){
          for(int j=0;j<n;j++){
               if(i<j){
                    dp[i][j]=max((long long)v[i]-dp[i+1][j],(long long)v[j]-dp[i][j-1]);
               // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
               }
               
          }
     }
     cout<<dp[0][n-1]<<endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[3001][3001];


int maxscore(int i,int j,int a[]){
    if(i>j){return 0;}
    if(j==i){return a[i];}
    if(j-i == 1){return max(a[i],a[j]);}
    if(dp[i][j] != -1){return dp[i][j];}

    int op1 = a[i] + min(maxscore(i+2,j,a),maxscore(i+1,j-1,a));
    int op2 = a[j] + min(maxscore(i+1,j-1,a),maxscore(i,j-2,a));

    return dp[i][j] = max(op1,op2);
    
}
 
 int32_t main(){
     int n;
     cin>>n;
     int a[n+1];
     a[0] = 0;
     int total = 0;
     for(int i=1;i<=n;i++){
         cin>>a[i];
         total += a[i];
     }
     memset(dp,-1,sizeof dp);
     int x = maxscore(1,n,a);
     cout<<2*x-total;
 }
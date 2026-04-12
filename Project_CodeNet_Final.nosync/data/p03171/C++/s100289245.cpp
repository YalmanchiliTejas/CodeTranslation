#include<bits/stdc++.h>
using namespace std ; 
long long int dp[3001][3001][2] ; 
long long int solve(int& n,vector<int>& l,int i,int j,int turn){
    if(i>j){
        //invalid subarray . 
        return 0 ; 
    }
    if(dp[i][j][turn]!=-1){
        return dp[i][j][turn] ; 
    }
    //otherwise . 
    if(turn==0){
        return dp[i][j][turn]=max(l[i]+solve(n,l,i+1,j,1),l[j]+solve(n,l,i,j-1,1)) ; 
    }else{
        return dp[i][j][turn]= min(solve(n,l,i+1,j,0),solve(n,l,i,j-1,0)) ; 
    }

}
int main(){
    int n ; cin>>n ; 
    vector<int> l(n+1) ; 
    for(int i =1 ; i<=n; i++){
        cin>>l[i]  ; 
    }
    //list use karke we can access both ends . 
    long long int sum = 0 ; 
for(int i =1 ; i<=n ; i++){
    sum+=l[i] ; 
}
   memset(dp,-1,sizeof(dp)) ; 
   long long int scorex = solve(n,l,1,n,0) ; 
   long long int scorey = sum-scorex ; 
   cout<<scorex-scorey<<"\n" ; 
   
   return 0 ; 
}

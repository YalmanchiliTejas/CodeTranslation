#include<bits/stdc++.h>
using namespace std;
vector<vector<long>> dp;
vector<long>nums;
// int solve(int i,int j){
//     if(i>j) return 0;
//     else{
        
//     }
// }

int main(){
    int size;
    cin>>size;
    nums.resize(size,0);
    dp.resize(size,vector<long>(size));
    // dpy.resize(size,0);
    
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    for(int i=size-1;i>=0;i--){
        
        for(int j=i;j<size;j++){
            if(i==j) dp[i][j]=nums[i];
            else dp[i][j]=max((i+1<size)?nums[i]-dp[i+1][j]:0,(j-1>=0)?nums[j]-dp[i][j-1]:0);
        }
    }
    long ans=dp[0][size-1];
    // solve(0,size-1);
    cout<<ans;
    return 0;
    
    
}